from PCA9955B_Base import PCA9955B_Base
from smbus2 import SMBus

class PCA9955B(PCA9955B_Base):
        def __init__(self, addr):
                #print("constructor")
                super().__init__(addr,1)
        
        def i2c_write(self, register, data):
                try:
                        with SMBus(self.i2c_bus) as bus:
                                # Schreibe die Daten an das angegebene Register
                                bus.write_i2c_block_data(self.dev_address, register, [data])
                                #print(f"Data {data} written to device at register {register}.")
                except Exception as e:
                        print(f"Error writing i2c data: {e}")
        
        def i2c_read(self, register, length):
                try:
                        with SMBus(self.i2c_bus) as bus:
                                # Lies `length` Bytes vom angegebenen Register
                                data = bus.read_i2c_block_data(self.dev_address, register, length)
                                #print(f"Received data: {data}")
                                return data
                except Exception as e:
                        print(f"Error reading i2c data: {e}")
