#include <iostream>
#include "PCA9955B.h"

int main(int argc, char **argv)
{
PCA9955B PCF;
uint8_t buffer1[10]={0x55,0,0,0,0,0,0,0,0,0};
uint8_t buffer2[10]={0xFE,0,0,0,0,0,0,0,0,0};
uint8_t buffer3[10]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

LEDOUT0_t *LEDOUT0=(LEDOUT0_t *)&buffer1[0];

IREFALL_t *IREFALL=(IREFALL_t *)&buffer2[0];

//LEDOUT0->LDR0=PCA9955B_LEDOUTX_LDRX_LEDFULLON;
//LEDOUT0->LDR1=PCA9955B_LEDOUTX_LDRX_LEDFULLON;
//LEDOUT0->LDR2=PCA9955B_LEDOUTX_LDRX_LEDFULLON;

PCF.WriteNonIncremental(PCA9955B::LEDOUT0,buffer1[0]);
PCF.ReadNonIncremental(PCA9955B::LEDOUT0,&buffer3[0]);

std::cout << "\nbuffer3[0]=" << std::hex << (int)buffer3[0] << "\nbuffer3[1]=" << (int)buffer3[1] << "\nbuffer3[2]=" << (int)buffer3[2] << "\nbuffer3[3]=" << (int)buffer3[3];

return 0;
}

