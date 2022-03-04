/**	@mainpage 	PCA9955B, a multi platform C++ software module.
 *	@version	0.7
 *	@image 		html Logo.png*/
 
#include <iostream>
#include <cstring>
#include "PCA9955B.h"

/**		PCA9955B example program
 * 	@file		main.cpp
 * 	@version	0.7
 * 	@author		Ludwig Schink
 * 	@date		04.03.2022
 * 	@brief		Entry point for program.*/
int main(int argc, char **argv)
{
PCA9955B PCA;

uint8_t imagebuffer[PCA9955B_Base::reg_addr_end];
uint8_t alloffbuffer[]={0x00,0x00,0x00,0x00};

IREFALL_t irefall=0xFE;

LEDOUT0_t ledout0={PCA9955B_LEDOUTX_LDRX_LEDPWM,
				   PCA9955B_LEDOUTX_LDRX_LEDPWM,
				   PCA9955B_LEDOUTX_LDRX_LEDPWM,
				   PCA9955B_LEDOUTX_LDRX_LEDPWM};

LEDOUT1_t ledout1={PCA9955B_LEDOUTX_LDRX_LEDFULLON,
				   PCA9955B_LEDOUTX_LDRX_LEDFULLON,
				   PCA9955B_LEDOUTX_LDRX_LEDFULLON,
				   PCA9955B_LEDOUTX_LDRX_LEDFULLON};

LEDOUT2_t ledout2={PCA9955B_LEDOUTX_LDRX_LEDFULLON,
				   PCA9955B_LEDOUTX_LDRX_LEDFULLON,
				   PCA9955B_LEDOUTX_LDRX_LEDFULLON,
				   PCA9955B_LEDOUTX_LDRX_LEDFULLON};

LEDOUT3_t ledout3={PCA9955B_LEDOUTX_LDRX_LEDFULLON,
				   PCA9955B_LEDOUTX_LDRX_LEDFULLON,
				   PCA9955B_LEDOUTX_LDRX_LEDFULLON,
				   PCA9955B_LEDOUTX_LDRX_LEDFULLON};

std::cout << "Setting all LEDs off" << std::endl;
PCA.WriteIncremental(PCA9955B::LEDOUT0,alloffbuffer,4);

std::cout << "Setting IREFALL register to 0xFE, press any key to coninue" << std::endl;
getchar();
PCA.WriteNonIncremental(PCA9955B::IREFALL,*((uint8_t*)&irefall));

std::cout << "Setting PWM0-3 register, press any key to continue" << std::endl;
getchar();
PCA.SetPWM0(0x60);
PCA.SetPWM1(0x30);
PCA.SetPWM2(0x20);
PCA.SetPWM3(0x10);
PCA.SetLEDOUT0(ledout0);

std::cout << "Setting LEDOUT1 register, press any key to continue" << std::endl;
getchar();
PCA.SetLEDOUT1(ledout1);

std::cout << "Setting LEDOUT2 register, press any key to continue" << std::endl;
getchar();
PCA.SetLEDOUT2(ledout2);

std::cout << "Setting LEDOUT3 register, press any key to continue" << std::endl;
getchar();
PCA.SetLEDOUT3(ledout3);

std::cout << "Lets get an image of all registers, press any key to continue" << std::endl;
getchar();
PCA.ReadIncremental(0x00,imagebuffer,PCA9955B_Base::reg_addr_end-1);
for(int i=0;i<PCA9955B_Base::reg_addr_end;i++)
	{
	std::cout << "addr " << std::hex << i << " " << std::hex << (int)imagebuffer[i] << std::endl;
	}
PCA.SetOutputEnable(PCA9955B_OEPIN_UP);

return 0;
}

