/**		PCA9955B PWM LED driver base class
 * 	@file		PCA9955B_Base.h
 * 	@version	0.3
 * 	@author		Ludwig Schink
 * 	@date		08.09.2021
 * 	@brief		This file contains the PCA9955B_Base class. Inherit from it, reimplement the virtual
 * 				functions and you can use the PCA9955B on every platform.*/


#ifndef PCA9955B_BASE_T_H
#define PCA9955B_BASE_T_H

#define PCA9955B_BUF_LEN 20

#define PCA9955B_READ	1
#define PCA9955B_WRITE	0

#define PCA9955B_INCREMENT 1
#define PCA9955B_NONINCREMENT 0

#define PCA9955B_LEDOUTX_LDRX_LEDOFF 	0b00
#define PCA9955B_LEDOUTX_LDRX_LEDFULLON	0b01
#define PCA9955B_LEDOUTX_LDRX_LEDPWM 	0b10
#define PCA9955B_LEDOUTX_LDRX_LEDBLINK 	0b11

#define PCA9955B_GRAD_CNTL_START  1
#define PCA9955B_GRAD_CNTL_STOP   0
#define PCA9955B_GRAD_CNTL_SINGLE 0
#define PCA9955B_GRAD_CNTL_CONT   1

#define PCA9955B_OFFSET_NODELAY  0b0000
#define PCA9955B_OFFSET_1CYCLES  0b0001
#define PCA9955B_OFFSET_2CYCLES  0b0010
#define PCA9955B_OFFSET_3CYCLES  0b0011
#define PCA9955B_OFFSET_4CYCLES  0b0100
#define PCA9955B_OFFSET_5CYCLES  0b0101
#define PCA9955B_OFFSET_6CYCLES  0b0110
#define PCA9955B_OFFSET_7CYCLES  0b0111
#define PCA9955B_OFFSET_8CYCLES  0b1000
#define PCA9955B_OFFSET_9CYCLES  0b1001
#define PCA9955B_OFFSET_10CYCLES 0b1010
#define PCA9955B_OFFSET_11CYCLES 0b1011
#define PCA9955B_OFFSET_12CYCLES 0b1100
#define PCA9955B_OFFSET_13CYCLES 0b1101
#define PCA9955B_OFFSET_14CYCLES 0b1110
#define PCA9955B_OFFSET_15CYCLES 0b1111

#define PCA9955B_ERRX_NORMAL 0b00
#define PCA9955B_ERRX_SHORT	 0b01
#define PCA9955B_ERRX_OPEN	 0b10
#define PCA9955B_ERRX_DNE	 0b11

#include <cstdint>
//todo: beschreibung der register einfügen
struct {
	   unsigned ALLCALL : 1;
	   unsigned SUB3	: 1;
	   unsigned SUB2	: 1;
	   unsigned SUB1	: 1;
	   unsigned SLEEP	: 1;
	   unsigned AI		: 2;
	   unsigned AIF		: 1;
	   }__attribute__((packed))typedef MODE1_t;

struct {
	   unsigned RESERVED : 2;
	   unsigned EXP_EN   : 1;
	   unsigned OCH		 : 1;
	   unsigned CLRERR	 : 1;
	   unsigned DMBLNK	 : 1;
	   unsigned ERROR	 : 1;
	   unsigned OVERTEMP : 1;
	   }__attribute__((packed))typedef MODE2_t;

struct {
	   unsigned LDR0 : 2;
	   unsigned LDR1 : 2;
	   unsigned LDR2 : 2;
	   unsigned LDR3 : 2;
	   }__attribute__((packed))typedef LEDOUT0_t; 

struct {
	   unsigned LDR4 : 2;
	   unsigned LDR5 : 2;
	   unsigned LDR6 : 2;
	   unsigned LDR7 : 2;
	   }__attribute__((packed))typedef LEDOUT1_t; 

struct {
	   unsigned LDR8 : 2;
	   unsigned LDR9 : 2;
	   unsigned LDR10 : 2;
	   unsigned LDR11 : 2;
	   }__attribute__((packed))typedef LEDOUT2_t;

struct {
	   unsigned LDR12 : 2;
	   unsigned LDR13 : 2;
	   unsigned LDR14 : 2;
	   unsigned LDR15 : 2;
	   }__attribute__((packed))typedef LEDOUT3_t;

typedef uint8_t GRPPWM_t;	//default: 0xFF, GRPPWM register, see p.19 in datasheet for more info.
typedef uint8_t GRPFREQ_t;	//default: 0x00, GRPFREQ register, see p.20 in datasheet for more info.

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
//todo: test!
typedef uint8_t IREF0_t; //default: 0x00, LED0 output current setting
typedef uint8_t IREF1_t; //default: 0x00, LED1 output current setting
typedef uint8_t IREF2_t; //default: 0x00, LED2 output current setting
typedef uint8_t IREF3_t; //default: 0x00, LED3 output current setting
typedef uint8_t IREF4_t; //default: 0x00, LED4 output current setting
typedef uint8_t IREF5_t; //default: 0x00, LED5 output current setting
typedef uint8_t IREF6_t; //default: 0x00, LED6 output current setting
typedef uint8_t IREF7_t; //default: 0x00, LED7 output current setting
typedef uint8_t IREF8_t; //default: 0x00, LED8 output current setting
typedef uint8_t IREF9_t; //default: 0x00, LED9 output current setting
typedef uint8_t IREF10_t; //default: 0x00, LED10 output current setting
typedef uint8_t IREF11_t; //default: 0x00, LED11 output current setting
typedef uint8_t IREF12_t; //default: 0x00, LED12 output current setting
typedef uint8_t IREF13_t; //default: 0x00, LED13 output current setting
typedef uint8_t IREF14_t; //default: 0x00, LED14 output current setting
typedef uint8_t IREF15_t; //default: 0x00, LED15 output current setting


struct {
	   unsigned RAMP_RATE : 6;	//default: 0, Ramp rate value per step is defined from 1 (0x00) to 64 (0x3F), see p.23 in datasheet
	   unsigned RAMP_DOWN : 1;	//default: 0, Ramp-down enable(1)/disable(0)
	   unsigned RAMP_UP	  : 1;	//default: 0, Ramp-up enable(1)/disale(0)
	   }__attribute__((packed))typedef RAMP_RATE_GRPX_t; //default: 0x00, rampe rate control register

struct {
	   unsigned MULTIFACTOR : 6; //default 0, Multiple factor per step (p.23)
	   unsigned CYCLETIME	: 1; //default 0, Cycle time 0.5ms (0)/Cylce time 8ms (1)
	   }__attribute__((packed))typedef STEP_TIME_GRPX_t; //default: 0x00, step time control register

struct {
	   unsigned HOLDOFFTIMESEL : 3;	//default 0, todo: description!
	   unsigned HOLDONTIMESEL  : 3; //default 0, todo: description!
	   unsigned HOLDOFF		   : 1; //default 0, todo: description!
	   unsigned HOLDON 		   : 1; //default 0, todo: description!
	   }__attribute__((packed))typedef HOLD_CNTL_GRPX_t; //default 0x00, hold on and off control registers

typedef uint8_t IREF_GRPX_t; //default: Final and hold ON gain setting registers
typedef uint8_t GRAD_MODE_SEL0_t; //default: 0x00, Gradiaton mode select registers for channel 0 to 7.
typedef uint8_t GRAD_MODE_SEL1_t; //default: 0x00, Gradiaton mode select registers for channel 0 to 7.
   
struct {
	   unsigned GRP_SELECT_LED0 : 2; //default: 0b00, Gradiation group select for LED0 output.
	   unsigned GRP_SELECT_LED1 : 2; //default: 0b00, Gradiation group select for LED0 output.
	   unsigned GRP_SELECT_LED2 : 2; //default: 0b00, Gradiation group select for LED0 output.
	   unsigned GRP_SELECT_LED3 : 2; //default: 0b00, Gradiation group select for LED0 output.
	   }__attribute__((packed))typedef GRAD_GRP_SEL0_t; //default: 0x00, Gradiation group select registers.

struct {
	   unsigned GRP_SELECT_LED4 : 2; //default: 0b01, Gradiation group select for LED0 output.
	   unsigned GRP_SELECT_LED5 : 2; //default: 0b01, Gradiation group select for LED0 output.
	   unsigned GRP_SELECT_LED6 : 2; //default: 0b01, Gradiation group select for LED0 output.
	   unsigned GRP_SELECT_LED7 : 2; //default: 0b01, Gradiation group select for LED0 output.
	   }__attribute__((packed))typedef GRAD_GRP_SEL1_t; //default: 0x55, Gradiation group select registers.
	   
struct {
	   unsigned GRP_SELECT_LED8 : 2; //default: 0b10, Gradiation group select for LED0 output.
	   unsigned GRP_SELECT_LED9 : 2; //default: 0b10, Gradiation group select for LED0 output.
	   unsigned GRP_SELECT_LED10 : 2; //default: 0b10, Gradiation group select for LED0 output.
	   unsigned GRP_SELECT_LED11 : 2; //default: 0b10, Gradiation group select for LED0 output.
	   }__attribute__((packed))typedef GRAD_GRP_SEL2_t; //default: 0xAA, Gradiation group select registers.

struct {
	   unsigned GRP_SELECT_LED12 : 2; //default: 0b11, Gradiation group select for LED0 output.
	   unsigned GRP_SELECT_LED13 : 2; //default: 0b11, Gradiation group select for LED0 output.
	   unsigned GRP_SELECT_LED14 : 2; //default: 0b11, Gradiation group select for LED0 output.
	   unsigned GRP_SELECT_LED15 : 2; //default: 0b11, Gradiation group select for LED0 output.
	   }__attribute__((packed))typedef GRAD_GRP_SEL3_t; //default: 0xFF, Gradiation group select registers.
	   
struct {
	   unsigned SHOT3  : 1; //default: 0, Single shot(0)/continous shot(1) for group 3
	   unsigned START3 : 1; //default: 0, stop or done(0)/start(1) for group 3
	   unsigned SHOT2   : 1; //default: 0, Single shot(0)/continous shot(1) for group 2
	   unsigned START2 : 1; //default: 0, stop or done(0)/start(1) for group 2
	   unsigned SHOT1  : 1; //default: 0, Single shot(0)/continous shot(1) for group 1
	   unsigned START1 : 1; //default: 0, stop or done(0)/start(1) for group 1
	   unsigned SHOT0  : 1; //default: 0, Single shot(0)/continous shot(1) for group 0
	   unsigned START0 : 1; //default: 0, stop or done(0)/start(1) for group 0
	   }__attribute__((packed))typedef GRAD_CNTL_t; //default: 0x00, Gradiation control register
	   
struct {
	   unsigned FACTOR : 4; //default: 0b1000, LEDn output delay offset value. Documentation for default value is not very clear at this point (p. 30).
	   unsigned RESERVED: 4; //default: 0b0000, not used
	   }__attribute__((packed))typedef OFFSET_t; //default: 0x08;
	   
struct {
	   unsigned RESERVED    : 1; //default: 0, reserved.
	   unsigned SUBADDRESS1 : 7; //default: 0x76, sub address 1
	   }__attribute__((packed))typedef SUBADR1_t; //default: 0xEC, i2c subaddress

struct {
	   unsigned RESERVED    : 1; //default: 0, reserved.
	   unsigned SUBADDRESS2 : 7; //default: 0x76, sub address 1
	   }__attribute__((packed))typedef SUBADR2_t; //default: 0xEC, i2c subaddress

struct {
	   unsigned RESERVED    : 1; //default: 0, reserved.
	   unsigned SUBADDRESS3 : 7; //default: 0x76, sub address 1
	   }__attribute__((packed))typedef SUBADR3_t; //default: 0xEC, i2c subaddress
	   
struct {
	   unsigned RESERVED : 		 1; //default: 0, reserved.
	   unsigned ALLCALLADDRESS : 7; //default: 0x70, AllCall i2c bus address
	   }__attribute__((packed))typedef ALLCALLADR_t; //default: 0xE0, LED All Call i2c-bus address register
	   
typedef uint8_t PWMALL_t; //default: 0x00, brightness control for all LEDn outputs. Duty Cycle for all LED outputs.
	   
typedef uint8_t IREFALL_t; //default: 0x00, Output gain control for all LED outputs. Current gain setting for all LED outputs.
	   
struct {
	   unsigned ERR0 : 2; //default: 0b00, Error status for LED0 output.
	   unsigned ERR1 : 2; //default: 0b00, Error status for LED1 output.
	   unsigned ERR2 : 2; //default: 0b00, Error status for LED2 output.
	   unsigned ERR3 : 2; //default: 0b00, Error status for LED3 output.
	   }__attribute__((packed))typedef EFLAG0_t; //default: 0x00, Error flag registers

struct {
	   unsigned ERR4 : 2; //default: 0b00, Error status for LED4 output.
	   unsigned ERR5 : 2; //default: 0b00, Error status for LED5 output.
	   unsigned ERR6 : 2; //default: 0b00, Error status for LED6 output.
	   unsigned ERR7 : 2; //default: 0b00, Error status for LED7 output.
	   }__attribute__((packed))typedef EFLAG1_t; //default: 0x00, Error flag registers

struct {
	   unsigned ERR8 : 2; //default: 0b00, Error status for LED8 output.
	   unsigned ERR9 : 2; //default: 0b00, Error status for LED9 output.
	   unsigned ERR10 : 2; //default: 0b00, Error status for LED10 output.
	   unsigned ERR11 : 2; //default: 0b00, Error status for LED11 output.
	   }__attribute__((packed))typedef EFLAG2_t; //default: 0x00, Error flag registers

struct {
	   unsigned ERR12 : 2; //default: 0b00, Error status for LED12 output.
	   unsigned ERR13 : 2; //default: 0b00, Error status for LED13 output.
	   unsigned ERR14 : 2; //default: 0b00, Error status for LED14 output.
	   unsigned ERR15 : 2; //default: 0b00, Error status for LED15 output.
	   }__attribute__((packed))typedef EFLAG3_t; //default: 0x00, Error flag registers

struct {
       unsigned readwrite :		1;	   
	   unsigned address	  :		7;
       }__attribute__((packed)) typedef i2c_header_t;

struct {
	   unsigned D	: 7; //default: 0x00, register address.
	   unsigned AIF	: 1; //default: todo: herausfinden
	   } __attribute__((packed)) typedef control_t; //default: todo: herausfinden, Control register.

struct {
	   i2c_header_t i2c_header;
	   control_t control;
	   }__attribute__((packed))typedef pca9955b_header_t;

class PCA9955B_Base
{
public:
PCA9955B_Base(uint8_t i2c_address);
~PCA9955B_Base(void);

enum interrupt {int_active=0x0,
				int_inactive=0x1};
				 
enum Errors {Errors_CouldNotSetOutputEnable=-6,
			 Errors_InkombatibelI2CAddress=-5,
			 Errors_ErrorUnknownFlag=-4,
			 Errors_ErrorUnknown=-3,
			 Errors_FailedWrite=-2,
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
			  IREF0=0x18,
			  IREF1=0x19,
			  IREF2=0x1A,
			  IREF3=0x1B,
			  IREF4=0x1C,
			  IREF5=0x1D,
			  IREF6=0x1E,
			  IREF7=0x1F,
			  IREF8=0x20,
			  IREF9=0x21,
			  IREF10=0x22,
			  IREF11=0x23,
			  IREF12=0x24,
			  IREF13=0x25,
			  IREF14=0x26,
			  IREF15=0x27,
			  RAMP_RATE_GRP0=0x28,
			  STEP_TIME_GRP0=0x29,
			  HOLD_CNTL_GRP0=0x2A,
			  IREF_GRP0=0x2B,
			  RAMP_RATE_GRP1=0x2C,
			  STEP_TIME_GRP1=0x2D,
			  HOLD_CNTL_GRP1=0x2E,
			  IREF_GRP1=0x2F,
			  RAMP_RATE_GRP2=0x30,
			  STEP_TIME_GRP2=0x31,
			  HOLD_CNTL_GRP2=0x32,
			  IREF_GRP2=0x33,
			  RAMP_RATE_GRP3=0x34,
			  STEP_TIME_GRP3=0x35,
			  HOLD_CNTL_GRP3=0x36,
			  IREF3_GRP=0x37,
			  GRAD_MODE_SEL0=0x38,
			  GRAD_MODE_SEL1=0x39,
			  GRAD_GRP_SEL0=0x3A,
			  GRAD_GRP_SEL1=0x3B,
			  GRAD_GRP_SEL2=0x3C,
			  GRAD_GRP_SEL3=0x3D,
			  GRAD_CNTL=0x3E,
			  OFFSET=0x3F,
			  SUBADR1=0x40,
			  SUBADR2=0x41,
			  SUBADR3=0x42,
			  ALLCALLADR=0x43,
			  PWMALL=0x44,
			  IREFALL=0x45,
			  EFLAG0=0x46,
			  EFLAG1=0x47,
			  EFLAG2=0x48,
			  EFLAG3=0x49,
			  reg_addr_end
			  };
				 
int8_t lasterror=Errors_NoError;
uint8_t i2c_dev_address=0;
uint8_t buffer[PCA9955B_BUF_LEN];

pca9955b_header_t *header=(pca9955b_header_t*)buffer;

/**		int i2cRXTX(uint8_t txbuf[],int bytes,bool rxtx)
 * 	@brief	Declared virtual for overriding by inheriting this class
 * 			You must provide this funtion to access the HW i2c controller.
 * 	@param [uint8_t] txbuf:	txdata to send or fill when receive
 * 	@param [int]		bytes:	number bytes to send
 * 	@param [bool]	rxtx:	read or write*/
virtual int i2cRXTX(int addr,uint8_t data[],int bytes,bool rxtx);

/**	int ReadNonIncremental(uint8_t reg_addr,uint8_t txdata[],int numbytes)
 * 	@brief	Declaring 
 * 	@param [int]		numtxbytes: Number of Bytes to read.
 * 	@return [int]		Value < 0 when error, 0 when success.*/
virtual int SetOutputEnable(uint8_t value);


/**		int i2cRXTX(uint8_t txbuf[],int bytes,bool rxtx)
 * 	@brief	Declared virtual for overriding by inheriting this class
 * 			You must provide this funtion to access the HW i2c controller.
 * 	@param [uint8_t] txbuf:	txdata to send or fill when receive
 * 	@param [int]		bytes:	number bytes to send
 * 	@param [bool]	rxtx:	read or write*/
int WriteIncremental(uint8_t reg_addr,uint8_t txdata[],int numtxbytes);

/**	int SendNonIncremental(uint8_t reg_addr,uint8_t txdata[],int numbytes)
 * 	@brief	Sends data to the device and increments register address
 * 			with every byte writed.
 * 	@param [uint8_t]	reg_addr:	device register address
 * 	@param [uint8_t*]	txdata:		buffer holding bytes to be sended.*/
int WriteNonIncremental(uint8_t reg_addr,uint8_t txbyte); 

/**	int ReadIncremental(uint8_t reg_addr,uint8_t txdata[],int numbytes)
 * 	@brief	todo:
 * 	@param [uint8_t]	reg_addr:	device register address
 * 	@param [uint8_t*]	txdata:		buffer holding bytes to be sended.
 * 	@param [int]		numtxbytes: Number of Bytes to be sended.
 * 	@return [int]		Number of read bytes or value < 0 when error.*/
int ReadIncremental(uint8_t reg_addr,uint8_t rxdata[],int numtxbytes); 

/**	int ReadNonIncremental(uint8_t reg_addr,uint8_t txdata[],int numbytes)
 * 	@brief	todo:
 * 	@param [uint8_t]	reg_addr:	device register address
 * 	@param [uint8_t*]	rxdata:		buffer to write the received bytes.
 * 	@param [int]		numtxbytes: Number of Bytes to read.
 * 	@return [int]		Number of read bytes or value < 0 when error.*/
int ReadNonIncremental(uint8_t reg_addr,uint8_t rxdata[]);

/**	int ClearErrors(void)
 * 	@brief	Sets 'lasterror' to 0 (Errors_NoErrors)*/
void ClearErrors(void);
};

#endif
