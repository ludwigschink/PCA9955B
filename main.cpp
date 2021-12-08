/**	@mainpage 	PCA9955B multi purpose class
 *	@version	0.5
 *	@image 		html default.png*/
 
#include <iostream>
#include <cstring>
#include "PCA9955B.h"

/**		PCA9955B example program
 * 	@file		main.cpp
 * 	@version	0.5
 * 	@author		Ludwig Schink
 * 	@date		08.12.2021
 * 	@brief		Entry point for program.*/
int main(int argc, char **argv)
{
PCA9955B PCF;

uint8_t alloffbuffer[]={0,0,0,0};
uint8_t rxbyte=0;
MODE2_t *MODE2=(MODE2_t*)&rxbyte;

IREFALL_t IREFALL=0xFE;

LEDOUT0_t LEDOUT0={PCA9955B_LEDOUTX_LDRX_LEDFULLON,
				   PCA9955B_LEDOUTX_LDRX_LEDFULLON,
				   PCA9955B_LEDOUTX_LDRX_LEDFULLON,
				   PCA9955B_LEDOUTX_LDRX_LEDFULLON};

LEDOUT1_t LEDOUT1={PCA9955B_LEDOUTX_LDRX_LEDOFF,
				   PCA9955B_LEDOUTX_LDRX_LEDOFF,
				   PCA9955B_LEDOUTX_LDRX_LEDOFF,
				   PCA9955B_LEDOUTX_LDRX_LEDOFF};

LEDOUT2_t LEDOUT2={PCA9955B_LEDOUTX_LDRX_LEDFULLON,
				   PCA9955B_LEDOUTX_LDRX_LEDOFF,
				   PCA9955B_LEDOUTX_LDRX_LEDFULLON,
				   PCA9955B_LEDOUTX_LDRX_LEDOFF};

LEDOUT3_t LEDOUT3={PCA9955B_LEDOUTX_LDRX_LEDFULLON,
				   PCA9955B_LEDOUTX_LDRX_LEDFULLON,
				   PCA9955B_LEDOUTX_LDRX_LEDFULLON,
				   PCA9955B_LEDOUTX_LDRX_LEDFULLON};

std::cout << "Setting all LEDs off" << std::endl;
PCF.WriteIncremental(PCA9955B::LEDOUT0,alloffbuffer,4);
std::cout << "Setting IREFALL register to 0xFE, press any key to coninue" << std::endl;
getchar();
PCF.WriteNonIncremental(PCA9955B::IREFALL,*((uint8_t*)&IREFALL));
std::cout << "Setting LEDOUT0 register, press any key to continue" << std::endl;
getchar();
PCF.WriteNonIncremental(PCA9955B::LEDOUT0,*((uint8_t*)&LEDOUT0));
std::cout << "Setting LEDOUT1 register, press any key to continue" << std::endl;
getchar();
PCF.WriteNonIncremental(PCA9955B::LEDOUT1,*((uint8_t*)&LEDOUT1));
std::cout << "Setting LEDOUT2 register, press any key to continue" << std::endl;
getchar();
PCF.WriteNonIncremental(PCA9955B::LEDOUT2,*((uint8_t*)&LEDOUT2));
std::cout << "Setting LEDOUT3 register, press any key to continue" << std::endl;
getchar();
PCF.WriteNonIncremental(PCA9955B::LEDOUT3,*((uint8_t*)&LEDOUT3));
std::cout << "Read MODE2 register for overtemp flag, press any key to continue" << std::endl;
getchar();
PCF.ReadNonIncremental(PCA9955B::MODE2,&rxbyte);
std::cout << "Overtemp:" << (int)MODE2->OVERTEMP << std::endl;

PCF.SetOutputEnable(PCA9955B_OEPIN_UP);

return 0;
}

