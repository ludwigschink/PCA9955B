/**		PCA9955B PWM LED driver class
 * 	@file		PCA9955B.cpp
 * 	@version	0.2
 * 	@author		Ludwig Schink
 * 	@date		08.09.2021
 * 	@brief		This file contains the PCA9955B class methods inherited from PCA9955B_Base.*/

#include "PCA9955B.h"
#include <cstring>
#include <iostream>

PCA9955B::PCA9955B(void)
: PCA9955B_Base(PCA9955B_DEV_ADDR)
{
//i2c
if ((file_i2c = open("/dev/i2c-1", O_RDWR)) < 0)
	{
	#ifdef PCA9955B_DEBUG
	//ERROR HANDLING: you can check errno to see what went wrong
	std::cout << "I2C: Failed to open the i2c bus";
	#endif
	}
if (ioctl(file_i2c, I2C_SLAVE, 0x15) < 0)
	{
	#ifdef PCA9955B_DEBUG
	std::cout << "I2C: Failed to acquire bus access and/or talk to slave.";
	//ERROR HANDLING; you can check errno to see what went wrong
	#endif
	}
}

PCA9955B::~PCA9955B(void)
{
close(file_i2c);
}

int PCA9955B::i2cRXTX(int addr,uint8_t buf[],int bytes,bool rxtx)
{
int ret=0;
#ifdef PCA9955B_DEBUG
std::cout << "DEBUG: in i2cRXTX\n" << "addr:" << std::hex << addr << ", operation:";
#endif
if(rxtx==i2c_read)
	{
	#ifdef PCA9955B_DEBUG
	std::cout << "read, bytes:" << (int)bytes-2 << "\n";
	for(int i=0;i<2;i++)
		{
		std::cout << "buf[" << i << "]=" << std::hex << (int)buf[i] << "\n";
		}
	#endif
	ret=write(file_i2c,&buf[1], 1);
	ret=read(file_i2c, &buf[2], bytes-2);	//todo: hard coded -2 gefällt mir nicht!
	if (ret != bytes-2)
		{
		#ifdef PCA9955B_DEBUG
		//ERROR HANDLING: i2c transaction failed
		std::cout << "I2C: Failed to read from i2c bus. return=" << ret << "\n";
		#endif
		return PCA9955B_Base::Errors::Errors_FailedRead;
		}
	}
else if(rxtx==i2c_write)
	{
	#ifdef PCA9955B_DEBUG
	std::cout << "write, bytes:" << (int)bytes << "\n";
	for(int i=0;i<bytes+2;i++)
		{
		std::cout << "buf[" << i << "]=" << std::hex << (int)buf[i] << "\n";
		}
	#endif
	ret=write(file_i2c, &buf[1], bytes+1);
	if (ret != bytes+1)
		{
		#ifdef PCA9955B_DEBUG
		//ERROR HANDLING: i2c transaction failed
		std::cout << "I2C: Failed write to i2c bus. return=" << ret << "\n";
		#endif
		return PCA9955B_Base::Errors::Errors_FailedRead;
		}
	}
else {
	 #ifdef PCA9955B_DEBUG
	 std::cout << "I2c: Data read:" << std::hex << (int)buf[0] << "," << std::hex << (int)buf[1];
	 #endif
	 }
lasterror=PCA9955B_Base::Errors::Errors_NoError;
return ret;
}
