#include <nds.h>

void fifocheck (void)
{
	if(fifoCheckValue32(FIFO_USER_07)) {
		if(fifoCheckValue32(FIFO_USER_04)) { REG_SCFG_CLK = 0x0181; }
		if(fifoCheckValue32(FIFO_USER_05)) { REG_SCFG_ROM = 0x703; }
		fifoSendValue32(FIFO_USER_07, 0);
	}
}

