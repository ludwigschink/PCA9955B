/**		PCA9955B PWM LED driver class
 * 	@file		PCA9955B.h
 * 	@version	0.6
 * 	@author		Ludwig Schink
 * 	@date		09.12.2021
 * 	@brief		This file contains the PCA9955B class inherited from PCA9955B_Base. It reimplementes
 * 				the virtual methods from PCA9955B_Base for using on Raspberry pi 3B+. It is meant
 * 				as an example for inheriting and reimplementation your own methods.*/

#ifndef PCA9955B_H
#define PCA9955B_H

#define PCA9955B_DEBUG	//active debug output (for system with iostream support only)
#define PCA9955B_DEV_ADDR 0x15

#define PCA9955B_OEPIN 0 //wiringpi pin 0 -> GPIO17
#define PCA9955B_OEPIN_DOWN 1
#define PCA9955B_OEPIN_UP 0

//includes for getting i2c working on raspberry pi
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include "wiringPi.h"

#include "PCA9955B_Base.h"

/**	PCA9955B
 * 	@brief	PCA9955B class for raspberry pi inherited from PCA9955B_Base class*/
class PCA9955B : public PCA9955B_Base
{
public:
PCA9955B(void);
~PCA9955B(void);

//These two methods are the ones you have to reimplement. They provide the hardware access.
/**		int i2cRXTX(uint8_t,int,bool)
 * 	@brief	Reimplementation for using in raspberry pi. For more information see PCA9955B_Base class*/
int i2cRXTX(int addr,uint8_t buf[],int bytes,bool rxtx);

/**		int i2cRXTX(uint8_t,int,bool)
 * 	@brief	Reimplementation for using in raspberry pi. For more information see PCA9955B_Base class*/
int SetOutputEnable(uint8_t value);

//Here are some examples for defining own methods for better accessing and using.
/**		int SetLEDOUT0(LEDOUT0_t ledout0)
 * 	@brief	Setting the LEDOUT0 registers.
 * 	@param [LEDOUT0_t] ledout0:	A LEDOUT0 object.*/
int SetLEDOUT0(LEDOUT0_t ledout0);

/**		int SetLEDOUT1(LEDOUT1_t ledout1)
 * 	@brief	Setting the LEDOUT1 registers.
 * 	@param [LEDOUT1_t] ledout1:	A LEDOUT1 object.*/
int SetLEDOUT1(LEDOUT1_t ledout1);

/**		int SetLEDOUT2(LEDOUT2_t ledout2)
 * 	@brief	Setting the LEDOUT2 registers.
 * 	@param [LEDOUT2_t] ledout2:	A LEDOUT2 object.*/
int SetLEDOUT2(LEDOUT2_t ledout2);

/**		int SetLEDOUT3(LEDOUT3_t ledout3)
 * 	@brief	Setting the LEDOUT3 registers.
 * 	@param [LEDOUT3_t] ledout3:	A LEDOUT3 object.*/
int SetLEDOUT3(LEDOUT3_t ledout3);

/**		int SetPWM0(PWM0_t pwm0)
 * 	@brief	Setting the LEDOUT3 registers.
 * 	@param [PWM0_t] pwm0:	A PWM0_t object.*/
int SetPWM0(PWM0_t pwm0);

/**		int SetPWM1(PWM1_t pwm1)
 * 	@brief	Setting the LEDOUT3 registers.
 * 	@param [PWM1_t] pwm1:	A PWM1_t object.*/
int SetPWM1(PWM1_t pwm1);

/**		int SetPWM2(PWM2_t pwm2)
 * 	@brief	Setting the LEDOUT3 registers.
 * 	@param [PWM2_t] pwm2:	A PWM2_t object.*/
int SetPWM2(PWM2_t pwm2);

/**		int SetPWM3(PWM3_t pwm3)
 * 	@brief	Setting the LEDOUT3 registers.
 * 	@param [PWM0_t] pwm0:	A PWM0_t object.*/
int SetPWM3(PWM3_t pwm3);

private:
int file_i2c=0;
};

#endif
