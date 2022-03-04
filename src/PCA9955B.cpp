/**		PCA9955B PWM LED driver class
 * 	@file		PCA9955B.cpp
 * 	@version	0.7
 * 	@author		Ludwig Schink
 * 	@date		04.03.2022
 * 	@brief		This file contains the PCA9955B class methods inherited from PCA9955B_Base.*/

#include "PCA9955B.h"
#include <cstring>
#include <iostream>

PCA9955B::PCA9955B(void)
: PCA9955B_Base(PCA9955B_DEV_ADDR)
{
gpioInitialise();
gpioSetMode(PCA9955B_OEPIN,PI_OUTPUT);
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
if(bytes<2)
	{
	std::cout << "I2C: incompatible byte count" << std::endl;
	return PCA9955B_Base::Errors::Errors_IncompatibleByteCount;
	}
int ret=0;
if(rxtx==i2c_read)
	{
	//uncomment for more information!
	//std::cout << "i2cRXTX(): write: buf[1]=" << std::hex << (int)buf[1] << " ,bytes=" << bytes << std::endl;
	ret=write(file_i2c,&buf[1], 1);			//&buf[1] because of the skipped address byte (its already sended by write() or read() function)
	ret=read(file_i2c, &buf[2], bytes-1);
	if (ret != bytes-1)
		{
		std::cout << "I2C: Failed to read from i2c bus. return=" << ret << std::endl;
		return PCA9955B_Base::Errors::Errors_FailedRead;
		}
	}
else if(rxtx==i2c_write)
	{
	//uncomment for more information!
	//std::cout << "i2cRXTX(): write: buf[1]=" << std::hex << (int)buf[1] << " ,bytes=" << bytes << std::endl;
	ret=write(file_i2c, &buf[1], bytes-1);	//&buf[1] because of the skipped address byte (its already sended by write() or read() function)
	if (ret != bytes-1)
		{
		std::cout << "I2C: Failed write to i2c bus. return=" << ret << std::endl;
		return PCA9955B_Base::Errors::Errors_FailedRead;
		}
	}
ClearLastError();
return ret;
}

int PCA9955B::SetOutputEnable(uint8_t value)
{
if(value==0)
	{
	gpioWrite(PCA9955B_OEPIN,0);
	}
else {
	 gpioWrite(PCA9955B_OEPIN,1);
	 }
return PCA9955B_Base::Errors::Errors_NoError;
}

int PCA9955B::SetLEDOUT0(LEDOUT0_t ledout0)
{
return WriteNonIncremental(LEDOUT0,*((uint8_t*)&ledout0));
}

int PCA9955B::SetLEDOUT1(LEDOUT1_t ledout1)
{
return WriteNonIncremental(LEDOUT1,*((uint8_t*)&ledout1));
}

int PCA9955B::SetLEDOUT2(LEDOUT2_t ledout2)
{
return WriteNonIncremental(LEDOUT2,*((uint8_t*)&ledout2));
}

int PCA9955B::SetLEDOUT3(LEDOUT3_t ledout3)
{
return WriteNonIncremental(LEDOUT3,*((uint8_t*)&ledout3));
}

int PCA9955B::SetPWM0(PWM0_t pwm0)
{
return WriteNonIncremental(PWM0,*((uint8_t*)&pwm0));
}

int PCA9955B::SetPWM1(PWM0_t pwm1)
{
return WriteNonIncremental(PWM1,*((uint8_t*)&pwm1));
}

int PCA9955B::SetPWM2(PWM0_t pwm2)
{
return WriteNonIncremental(PWM2,*((uint8_t*)&pwm2));
}

int PCA9955B::SetPWM3(PWM0_t pwm3)
{
return WriteNonIncremental(PWM3,*((uint8_t*)&pwm3));
}
