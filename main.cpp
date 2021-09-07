#include <iostream>
#include "PCA9955B.h"

int main(int argc, char **argv)
{
PCA9955B PCF;
uint8_t buffer[10]={0,0,0,0,0,0,0,0,0,0};
LEDOUT0_struct_t *LEDOUT0=(LEDOUT0_struct_t *)&buffer[0];
PWM0_t *PWM0=nullptr;

LEDOUT0->LDR0=PCA9955B_LEDOUTX_LDRX_LEDPWM;
LEDOUT0->LDR1=PCA9955B_LEDOUTX_LDRX_LEDOFF;
LEDOUT0->LDR2=PCA9955B_LEDOUTX_LDRX_LEDOFF;
LEDOUT0->LDR3=PCA9955B_LEDOUTX_LDRX_LEDOFF;

PCF.WriteNonIncremental(PCA9955B::LEDOUT0,buffer,1);
PWM0=(PWM0_t *)&buffer[0];
*PWM0=0x01;
PCF.WriteNonIncremental(PCA9955B::PWM0,buffer,1);

return 0;
}

