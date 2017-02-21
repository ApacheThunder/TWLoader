#include <nds.h>

int PowerOnSlot() {
	// Power On Slot
	while(REG_SCFG_MC&0x0C !=  0x0C); // wait until state<>3
	if(REG_SCFG_MC&0x0C != 0x00) return; //  exit if state<>0
	
	REG_SCFG_MC = 0x04;    // wait 1ms, then set state=1
	while(REG_SCFG_MC&0x0C != 0x04);
	
	REG_SCFG_MC = 0x08;    // wait 10ms, then set state=2      
	while(REG_SCFG_MC&0x0C != 0x08);
	
	REG_ROMCTRL = 0x20000000; // wait 27ms, then set ROMCTRL=20000000h
	
	while(REG_ROMCTRL&0x8000000 != 0x8000000);
	
}

int PowerOffSlot() {
	while(REG_SCFG_MC&0x0C !=  0x0C); // wait until state<>3
	if(REG_SCFG_MC&0x0C != 0x08) return 1; // exit if state<>2      
	
	REG_SCFG_MC = 0x0C; // set state=3 
	while(REG_SCFG_MC&0x0C != 0x00); // wait until state=0
}

void TWL_ResetSlot1() {
	PowerOffSlot();
	for (int i = 0; i < 30; i++) { swiWaitForVBlank(); }
	PowerOnSlot(); 
}

