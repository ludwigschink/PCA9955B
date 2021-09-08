/**		PCA9955B PWM LED driver base class
 * 	@file		PCA9955B_Base.cpp
 * 	@version	0.2
 * 	@author		Ludwig Schink
 * 	@date		08.09.2021
 * 	@brief		This file contains the PCA9955B_Base class method source.*/

#include <cstring>
#include "PCA9955B_Base.h"

#ifdef PCA9955B_DEBUG
#include <iostream>
#endif

PCA9955B_Base::PCA9955B_Base(uint8_t i2c_address)
{
	 #ifdef PCA9955B_DEBUG
	 std::cout << "DEBUG: in PCA9955B_Base()\n" << "i2c_address=" << std::hex << i2c_address << "\n";
	 #endif
std::memset(buffer,0,sizeof(PCA9955B_BUF_LEN));
if(i2c_address<=0x7D)
	{
	i2c_dev_address=i2c_address;
	}
else {
	 lasterror=Errors_InkombatibelI2CAddress;
	 #ifdef PCA9955B_DEBUG
	 std::cout << "ERR: invalid i2c device address";
	 #endif
	 }
}

PCA9955B_Base::~PCA9955B_Base()
{
}

int PCA9955B_Base::i2cRXTX(int addr,uint8_t txbuf[],int bytes,bool rxtx)
{
#ifdef PCA9955B_DEBUG
std::cout << "Addr:" << std::hex << addr << ", Buffer data:";
for(int i=0;i<=bytes;i++)
	{
	std::cout << std::hex << txbuf[i] << " ";
	}
std::cout << "\n";
#endif
return Errors_NoError;
}

int PCA9955B_Base::WriteNonIncremental(uint8_t reg_addr,uint8_t txbyte)
{
#ifdef PCA9955B_DEBUG
std::cout << "DEBUG: In WriteNonIncremental\n";
#endif
header->i2c_header.address=i2c_dev_address;
header->i2c_header.readwrite=i2c_write;
header->control.D=reg_addr;
header->control.AIF=PCA9955B_NONINCREMENT;
buffer[2+1]=txbyte;
#ifdef PCA9955B_DEBUG
for(int i=0;i<3;i++)
	{
	std::cout << "buffer[" << i << "]=" << std::hex << (int)buffer[i] << "\n";
	}
#endif
int ret=i2cRXTX(i2c_dev_address,buffer,2,i2c_write);
return ret;
}

int PCA9955B_Base::WriteIncremental(uint8_t reg_addr,uint8_t txdata[],int numtxbytes)
{
#ifdef PCA9955B_DEBUG
std::cout << "DEBUG: In WriteNonIncremental\n";
#endif
header->i2c_header.address=i2c_dev_address;
header->i2c_header.readwrite=i2c_write;
header->control.D=reg_addr;
header->control.AIF=PCA9955B_INCREMENT;
for(int i=0;i<numtxbytes;i++)
	{
	buffer[2+i]=txdata[i];
	}
#ifdef PCA9955B_DEBUG
for(int i=0;i<numtxbytes+2;i++)
	{
	std::cout << "buffer[" << i << "]=" << std::hex << (int)buffer[i] << "\n";
	}
#endif
int ret=i2cRXTX(i2c_dev_address,buffer,numtxbytes,i2c_write);
return ret;
} 

int PCA9955B_Base::ReadNonIncremental(uint8_t reg_addr,uint8_t *rxbyte)
{
	#ifdef PCA9955B_DEBUG
	std::cout << "DEBUG: in ReadNonIncremental\n";
	#endif
header->i2c_header.address=i2c_dev_address;
header->i2c_header.readwrite=i2c_write;
header->control.D=reg_addr;
header->control.AIF=PCA9955B_NONINCREMENT;
	#ifdef PCA9955B_DEBUG
	std::cout << "buffer[0]=" << std::hex << (int)buffer[0] << "\n";
	std::cout << "buffer[1]=" << std::hex << (int)buffer[1] << "\n";
	#endif
int ret=i2cRXTX(i2c_dev_address,buffer,1+2,i2c_read);
if(ret>0)
	{
	#ifdef PCA9955B_DEBUG
	std::cout << "Received bytes: " << ret << "\n";
	#endif
	*rxbyte=buffer[1+2];
	}
return ret;
}

int PCA9955B_Base::ReadIncremental(uint8_t reg_addr,uint8_t rxdata[],int numrxbytes)
{
	#ifdef PCA9955B_DEBUG
	std::cout << "DEBUG: in ReadNonIncremental\n";
	#endif
header->i2c_header.address=i2c_dev_address;
header->i2c_header.readwrite=i2c_write;
header->control.D=reg_addr;
header->control.AIF=PCA9955B_INCREMENT;
	#ifdef PCA9955B_DEBUG
	std::cout << "buffer[0]=" << std::hex << (int)buffer[0] << "\n";
	std::cout << "buffer[1]=" << std::hex << (int)buffer[1] << "\n";
	#endif
int ret=i2cRXTX(i2c_dev_address,buffer,numrxbytes+2,i2c_read);
if(ret>0)
	{
	#ifdef PCA9955B_DEBUG
	std::cout << "Received bytes: " << ret << "\n";
	#endif
	for(int i=0;i<ret;i++)
		{
		rxdata[i]=buffer[i+2];
		}
	}
return ret;
}
