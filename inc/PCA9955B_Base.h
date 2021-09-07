/**		PCA9955B PWM LED driver base class
 * 	@file		PCA9955B_Base.h
 * 	@version	0.1
 * 	@author		Ludwig Schink
 * 	@date		07.09.2021
 * 	@brief		This file contains the PCA9955B_Base class. Inherit from it, reimplement the virtual
 * 				functions and you can use the PCA9955B on every platform.*/


#ifndef PCA9955B_BASE_T_H
#define PCA9955B_BASE_T_H

#define PCA9955B_BUF_LEN 20
//#define PCA9955B_LINUX

#define PCA9955B_READ	1
#define PCA9955B_WRITE	0

//todo: drüber nachdenken, dass nicht vllt in die klasse zu stecken
#define PCA9955B_LEDOUTX_LDRX_LEDOFF 	0b00
#define PCA9955B_LEDOUTX_LDRX_LEDFULLON	0b01
#define PCA9955B_LEDOUTX_LDRX_LEDPWM 	0b10
#define PCA9955B_LEDOUTX_LDRX_LEDBLINK 	0b11


#include <cstdint>

struct {
	   }__attribute__((packed))typedef MODE1_struct_t; //todo: implement

struct {
	   }__attribute__((packed))typedef MODE2_struct_t; //todo: implement

struct {
	   unsigned LDR0 : 2;
	   unsigned LDR1 : 2;
	   unsigned LDR2 : 2;
	   unsigned LDR3 : 2;
	   }__attribute__((packed))typedef LEDOUT0_struct_t; 

struct {
	   unsigned LDR4 : 2;
	   unsigned LDR5 : 2;
	   unsigned LDR6 : 2;
	   unsigned LDR7 : 2;
	   }__attribute__((packed))typedef LEDOUT1_struct_t; 

struct {
	   unsigned LDR8 : 2;
	   unsigned LDR9 : 2;
	   unsigned LDR10 : 2;
	   unsigned LDR11 : 2;
	   }__attribute__((packed))typedef LEDOUT2_struct_t;

struct {
	   unsigned LDR12 : 2;
	   unsigned LDR13 : 2;
	   unsigned LDR14 : 2;
	   unsigned LDR15 : 2;
	   }__attribute__((packed))typedef LEDOUT3_struct_t;

struct {
	   unsigned LDR0 : 2;
	   unsigned LDR1 : 2;
	   unsigned LDR2 : 2;
	   unsigned LDR3 : 2;
	   }__attribute__((packed))typedef GRPPWM_struct_t; //todo: implement

struct {
	   unsigned LDR0 : 2;
	   unsigned LDR1 : 2;
	   unsigned LDR2 : 2;
	   unsigned LDR3 : 2;
	   }__attribute__((packed))typedef GRPFREQ_struct_t; //todo: implement

typedef uint8_t PWM0_t;		//PWM0 Individual Duty Cycle
typedef uint8_t PWM1_t;		//PWM1 Individual Duty Cycle
typedef uint8_t PWM2_t;		//PWM2 Individual Duty Cycle
typedef uint8_t PWM3_t;		//PWM3 Individual Duty Cycle
typedef uint8_t PWM4_t;		//PWM4 Individual Duty Cycle
typedef uint8_t PWM5_t;		//PWM5 Individual Duty Cycle
typedef uint8_t PWM6_t;		//PWM6 Individual Duty Cycle
typedef uint8_t PWM7_t;		//PWM7 Individual Duty Cycle
typedef uint8_t PWM8_t;		//PWM8 Individual Duty Cycle
typedef uint8_t PWM9_t;		//PWM9 Individual Duty Cycle
typedef uint8_t PWM10_t;	//PWM10 Individual Duty Cycle
typedef uint8_t PWM11_t;	//PWM11 Individual Duty Cycle
typedef uint8_t PWM12_t;	//PWM12 Individual Duty Cycle
typedef uint8_t PWM13_t;	//PWM13 Individual Duty Cycle
typedef uint8_t PWM14_t;	//PWM14 Individual Duty Cycle
typedef uint8_t PWM15_t;	//PWM15 Individual Duty Cycle

struct {
	   }__attribute__((packed))typedef IREF0_struct_t; //todo: implement

struct {
	   }__attribute__((packed))typedef IREF1_struct_t; //todo: implement

struct {
	   }__attribute__((packed))typedef IREF2_struct_t; //todo: implement

struct {
	   }__attribute__((packed))typedef IREF3_struct_t; //todo: implement

struct {
	   }__attribute__((packed))typedef IREF4_struct_t; //todo: implement

struct {
	   }__attribute__((packed))typedef IREF5_struct_t; //todo: implement

struct {
	   }__attribute__((packed))typedef IREF6_struct_t; //todo: implement

struct {
	   }__attribute__((packed))typedef IREF7_struct_t; //todo: implement

struct {
	   }__attribute__((packed))typedef IREF8_struct_t; //todo: implement

struct {
	   }__attribute__((packed))typedef IREF9_struct_t; //todo: implement

struct {
	   }__attribute__((packed))typedef IREF10_struct_t; //todo: implement

struct {
	   }__attribute__((packed))typedef IREF11_struct_t; //todo: implement

struct {
	   }__attribute__((packed))typedef IREF12_struct_t; //todo: implement

struct {
	   }__attribute__((packed))typedef IREF13_struct_t; //todo: implement

struct {
	   }__attribute__((packed))typedef IREF14_struct_t; //todo: implement

struct {
	   }__attribute__((packed))typedef IREF15_struct_t; //todo: implement

struct {
	   }__attribute__((packed))typedef RAMP_RATE_GRP0; //todo: implement

struct {
	   }__attribute__((packed))typedef STEP_TIME_GRP0; //todo: implement

struct {
	   }__attribute__((packed))typedef HOLD_CNTL_GRP0; //todo: implement

struct {
	   }__attribute__((packed))typedef IREF_GRP0; //todo: implement

struct {
	   }__attribute__((packed))typedef RAMP_RATE_GRP1; //todo: implement

struct {
	   }__attribute__((packed))typedef STEP_TIME_GRP1; //todo: implement

struct {
	   }__attribute__((packed))typedef HOLD_CNTL_GRP1; //todo: implement

struct {
	   }__attribute__((packed))typedef IREF_GRP1; //todo: implement

struct {
	   }__attribute__((packed))typedef RAMP_RATE_GRP2; //todo: implement

struct {
	   }__attribute__((packed))typedef STEP_TIME_GRP2; //todo: implement

struct {
	   }__attribute__((packed))typedef HOLD_CNTL_GRP2; //todo: implement

struct {
	   }__attribute__((packed))typedef IREF_GRP2_struct_t; //todo: implement
	   
struct {
	   }__attribute__((packed))typedef RAMP_RATE_GRP3_struct_t; //todo: implement
	   
struct {
	   }__attribute__((packed))typedef STEP_TIME_GRP3_struct_t; //todo: implement
	   
struct {
	   }__attribute__((packed))typedef HOLD_CNTL_GRP3_struct_t; //todo: implement
	   
struct {
	   }__attribute__((packed))typedef IREF_GRP3_struct_t; //todo: implement
	   
struct {
	   }__attribute__((packed))typedef GRAD_MODE_SEL0_struct_t; //todo: implement
	   
struct {
	   }__attribute__((packed))typedef GRAD_MODE_SEL1_struct_t; //todo: implement
	   
struct {
	   }__attribute__((packed))typedef GRAD_GRP_SEL0_struct_t; //todo: implement
	   
struct {
	   }__attribute__((packed))typedef GRAD_GRP_SEL1_struct_t; //todo: implement
	   
struct {
	   }__attribute__((packed))typedef GRAD_GRP_SEL2_struct_t; //todo: implement
	   
struct {
	   }__attribute__((packed))typedef GRAD_GRP_SEL3_struct_t; //todo: implement
	   
struct {
	   }__attribute__((packed))typedef GRAD_CNTL_struct_t; //todo: implement
	   
struct {
	   }__attribute__((packed))typedef OFFSET_struct_t; //todo: implement
	   
struct {
	   }__attribute__((packed))typedef SUBADR1_struct_t; //todo: implement
	   
struct {
	   }__attribute__((packed))typedef SUBADR2_struct_t; //todo: implement
	   
struct {
	   }__attribute__((packed))typedef SUBADR3_struct_t; //todo: implement
	   
struct {
	   }__attribute__((packed))typedef ALLCALLADR_struct_t; //todo: implement
	   
struct {
	   }__attribute__((packed))typedef PWMALL_struct_t; //todo: implement
	   
struct {
	   }__attribute__((packed))typedef IREFALL_struct_t; //todo: implement
	   
struct {
	   }__attribute__((packed))typedef EFLAG0_struct_t; //todo: implement
	   
struct {
	   }__attribute__((packed))typedef EFLAG1_struct_t; //todo: implement
	   
struct {
	   }__attribute__((packed))typedef EFLAG2_struct_t; //todo: implement
	   
struct {
	   }__attribute__((packed))typedef EFLAG3_struct_t; //todo: implement

struct {
       unsigned readwrite :		1;	   
	   unsigned address	  :		7;
       }__attribute__((packed)) typedef i2c_header_struct_t;

struct {
	   unsigned D	: 7;
	   unsigned AIF	: 1;
	   } __attribute__((packed)) typedef Control_struct_t;

struct {
	   i2c_header_struct_t i2c_header;
	   //Control_struct_t control;
	   }__attribute__((packed))typedef PCA9955B_Header_struct_t;

union {
	  PCA9955B_Header_struct_t Header_struct;
	  uint8_t bytes[PCA9955B_BUF_LEN+sizeof(i2c_header_struct_t)+sizeof(Control_struct_t)];
	  } typedef PCA9955B_Header_t;
	  
class PCA9955B_Base
{
public:
PCA9955B_Base(uint8_t i2c_address);
~PCA9955B_Base(void);

enum interrupt {int_active=0x0,
				int_inactive=0x1};
				 
enum Errors {Errors_InkombatibelI2CAddress=-4,
			 Errors_ErrorUnknownFlag=-3,
			 Errors_ErrorUnknown=-2,
			 Errors_FailedRead=-1,
			 Errors_NoError=0};

enum PCA9955B_i2c {
				  i2c_write=0,
				  i2c_read=1
				  };

enum reg_addr {
			  MODE1=0x00,
			  MODE2=0x01,
			  LEDOUT0=0x02,
			  LEDOUT1=0x03,
			  LEDOUT2=0x04,
			  LEDOUT3=0x05,
 			  GRPPWM=0x06,
			  GRPFREQ=0x07,
			  PWM0=0x08,
			  PWM1=0x09,
			  PWM2=0x0A,
			  PWM3=0x0B,
			  PWM4=0x0C,
			  PWM5=0x0D,
			  PWM6=0x0E,
			  PWM7=0x0F,
			  PWM8=0x10,
			  PWM9=0x11,
			  PWM10=0x12,
			  PWM11=0x13,
			  PWM12=0x14,
			  PWM13=0x15,
			  PWM14=0x16,
			  PWM15=0x17,
			  reg_addr_end
			  };//todo: zu ende implementieren
				 
int8_t lasterror=Errors_NoError;
uint8_t i2c_dev_address=0;
uint8_t buffer[PCA9955B_BUF_LEN];
PCA9955B_Header_t *header=(PCA9955B_Header_t*)buffer;
/**		int i2cRXTX(uint8_t txbuf[],int bytes,bool rxtx)
 * 	@brief	Declared virtual for overriding by inheriting this classstruct {
	   }__attribute__((packed))typedef 
 * 			You must provide this funtion to access the HW i2c controller.
 * 	@param[uint8_t] txbuf:	txdata to send or fill when receive
 * 	@param[int]		bytes:	number bytes to send
 * 	@param[bool]	rxtx:	read or write*/
virtual int i2cRXTX(int addr,uint8_t data[],int bytes,bool rxtx);

/**		int i2cRXTX(uint8_t txbuf[],int bytes,bool rxtx)
 * 	@brief	Declared virtual for overriding by inheriting this classstruct {
	   }__attribute__((packed))typedef 
 * 			You must provide this funtion to access the HW i2c controller.
 * 	@param[uint8_t] txbuf:	txdata to send or fill when receive
 * 	@param[int]		bytes:	number bytes to send
 * 	@param[bool]	rxtx:	read or write*/
int WriteIncremental(uint8_t reg_addr,uint8_t txdata[],int numtxbytes);

/**	int SendNonIncremental(uint8_t reg_addr,uint8_t txdata[],int numbytes)
 * 	@brief	Sends data to the device and increments register address
 * 			with every byte writed.
 * 	@param [uint8_t]	reg_addr:	device register address
 * 	@param [uint8_t*]	txdata:		buffer holding bytes to be sended.
 * 	@param [int]		numtxbytes: Number of Bytes to be sended.*/
int WriteNonIncremental(uint8_t reg_addr,uint8_t txdata[],int numtxbytes); 

/**	int ReadIncremental(uint8_t reg_addr,uint8_t txdata[],int numbytes)
 * 	@brief	todo:
 * 	@param [uint8_t]	reg_addr:	device register address
 * 	@param [uint8_t*]	txdata:		buffer holding bytes to be sended.
 * 	@param [int]		numtxbytes: Number of Bytes to be sended.*/
int ReadIncremental(uint8_t reg_addr,uint8_t rxdata[],int numtxbytes); 

/**	int ReadNonIncremental(uint8_t reg_addr,uint8_t txdata[],int numbytes)
 * 	@brief	todo:
 * 	@param [uint8_t]	reg_addr:	device register address
 * 	@param [uint8_t*]	rxdata:		buffer to write the received bytes.
 * 	@param [int]		numtxbytes: Number of Bytes to read.*/
int ReadNonIncremental(uint8_t reg_addr,uint8_t rxdata[],int numrxbytes); 

virtual bool GetInterrupt(void);
};

#endif
