from enum import Enum

class PCA9955B_Base:
        def __init__(self, i2c_address=0x02, i2c_bus=1):
                """
                Initialisiert die PCA9955B-Klasse.
                
                :param i2c_address: I2C-Adresse des PCA9955B (Standard: 0x02)
                :param i2c_bus: I2C-Busnummer des Raspberry Pi (Standard: 1)
                """
                self.dev_address = i2c_address
                self.i2c_bus = i2c_bus
        
        class registers(Enum):
                MODE1 = 0x00
                MODE2 = 0x01
                LEDOUT0 = 0x02
                LEDOUT1 = 0x03
                LEDOUT2 = 0x04
                LEDOUT3 = 0x05
                
                GROUP_PWM = 0x06
                GROUP_FREQ = 0x07
                
                PWM0 = 0x08
                PWM1 = 0x09
                PWM2 = 0x0A
                PWM3 = 0x0B
                PWM4 = 0x0C
                PWM5 = 0x0D
                PWM6 = 0x0E
                PWM7 = 0x0F
                PWM8 = 0x10
                PWM9 = 0x11
                PWM10 = 0x12
                PWM11 = 0x13
                PWM12 = 0x14
                PWM13 = 0x15
                PWM14 = 0x16
                PWM15 = 0x17
                
                IREF0 = 0x18
                IREF1 = 0x19
                IREF2 = 0x1A
                IREF3 = 0x1B
                IREF4 = 0x1C
                IREF5 = 0x1D
                IREF6 = 0x1E
                IREF7 = 0x1F
                IREF8 = 0x20
                IREF9 = 0x21
                IREF10 = 0x22
                IREF11 = 0x23
                IREF12 = 0x24
                IREF13 = 0x25
                IREF14 = 0x26
                IREF15 = 0x27
                
                RAMP_RATE_GRP0 = 0x28
                STEP_TIME_GRP0 = 0x29
                HOLD_CNTL_GRP0 = 0x2A
                IREF_GRP0 = 0x2B
                RAMP_RATE_GRP1 = 0x2C
                STEP_TIME_GRP1 = 0x2D
                HOLD_CNTL_GRP1 = 0x2E
                IREF_GRP1 = 0x2F
                RAMP_RATE_GRP2 = 0x30
                STEP_TIME_GRP2 = 0x31
                HOLD_CNTL_GRP2 = 0x32
                IREF_GRP2 = 0x33
                RAMP_RATE_GRP3 = 0x34
                STEP_TIME_GRP3 = 0x35
                HOLD_CNTL_GRP3 = 0x36
                IREF_GRP3 = 0x37
                                
                GRAD_MODE_SEL0=0x38
                GRAD_MODE_SEL1=0x38
                GRAD_MODE_SEL2=0x38
                GRAD_MODE_SEL3=0x38
                
                GRAD_CNTL = 0x3E
                OFFSET = 0x3F
                SUBADR1 = 0x40
                SUBADR2 = 0x41
                SUBADR3 = 0x42
                
                ALLCALLADR = 0x43
                PWMALL = 0x44
                IREFALL = 0x45
                
                EFLAG0 = 0x46
                EFLAG1 = 0x47
                EFLAG2 = 0x48
                EFLAG3 = 0x49

        def setLEDOUTX(self, X, value):
                i2c_write(registers.LEDOUT0 + X, value)

        def setIREFALL(self, value):
                i2c_write(registers.IREFALL, value)
                
        def setPWMALL(self, value):
                i2c_write(registers.PWMALL, value)
                
        def setPWMX(self, X, value):
                i2c_write(registers.PWM0 + X, value)
        
        def i2c_write(self, register, data):
                print(f"(dummy) i2c write: address: {self.i2c_address} register: {register} data: {data}")
        
        def i2c_read(self, register):
                print(f"(dummy) i2c write: address: {self.i2c_address} register: {register}")
        
