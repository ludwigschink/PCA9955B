/**		PCA9955B PWM LED driver class
 * 	@file		PCA9955B.cpp
 * 	@version	0.4
 * 	@author		Ludwig Schink
 * 	@date		08.12.2021
 * 	@brief		This file contains the PCA9955B class methods inherited from PCA9955B_Base.*/

#include "PCA9955B.h"
#include <cstring>
#include <iostream>

PCA9955B::PCA9955B(void)
: PCA9955B_Base(PCA9955B_DEV_ADDR)
{
//for gpio use
wiringPiSetup();
pinMode(PCA9955B_OEPIN,OUTPUT);
//i2c
if ((file_i2c = open("/dev/i2c-1", O_RDWR)) < 0)
	{
	std::cout << "I2C: Failed to open the i2c bus";
	}
if (ioctl(file_i2c, I2C_SLAVE, 0x15) < 0)
	{
	std::cout << "I2C: Failed to acquire bus access and/or talk to slave.";
	}
}

PCA9955B::~PCA9955B(void)
{
close(file_i2c);
}

int PCA9955B::i2cRXTX(int addr,uint8_t buf[],int bytes,bool rxtx)
{
int ret=0;
if(rxtx==i2c_read)
	{
	ret=write(file_i2c,&buf[1], 1);
	ret=read(file_i2c, &buf[2], bytes-2);	//todo: hard coded -2 gefällt mir nicht!
	if (ret != bytes-2)
		{
		std::cout << "I2C: Failed to read from i2c bus. return=" << ret << "\n";
		return PCA9955B_Base::Errors::Errors_FailedRead;
		}
	}
else if(rxtx==i2c_write)
	{
	ret=write(file_i2c, &buf[1], bytes+1);
	if (ret != bytes+1)
		{
		std::cout << "I2C: Failed write to i2c bus. return=" << ret << "\n";
		return PCA9955B_Base::Errors::Errors_FailedRead;
		}
	}
lasterror=PCA9955B_Base::Errors::Errors_NoError;
return ret;
}

int PCA9955B::SetOutputEnable(uint8_t value)
{
if(value==0)
	{
	digitalWrite(PCA9955B_OEPIN,0);
	}
else {
	 digitalWrite(PCA9955B_OEPIN,1);
	 }
return PCA9955B_Base::Errors::Errors_NoError;
}

int PCA9955B::SetLEDOUT0(LEDOUT0_t ledout)
{
//uint8_t txbyte=(uint8_t)ledout;
//WriteNonIncremental(LEDOUT0,txbyte);
return 0;
}
