/**		PCA9955B PWM LED driver class
 * 	@file		PCA9955B.h
 * 	@version	0.2
 * 	@author		Ludwig Schink
 * 	@date		08.09.2021
 * 	@brief		This file contains the PCA9955B class inherited from PCA9955B. It reimplementes
 * 				the virtual functions of PCA9955B_Base for using on raspberry pi 3B+.*/

#ifndef PCA9955B_H
#define PCA9955B_H

#define PCA9955B_DEBUG	//active debug output (for system with iostream support only)
#define PCA9955B_DEV_ADDR 0x15

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
/**		int i2cRXTX(uint8_t,int,bool)
 * 	@brief	Reimplementation for using in raspberry pi. For more information see PCA9955B_Base class*/
int i2cRXTX(int addr,uint8_t buf[],int bytes,bool rxtx);
private:
int file_i2c=0;
};

#endif
