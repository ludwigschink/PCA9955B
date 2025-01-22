from smbus2 import SMBus

# Adresse des I2C-Geräts (ersetzen mit der Adresse deines Geräts)
DEVICE_ADDRESS = 0x20  # Beispieladresse für einen PCF8575

# Register des Geräts (falls zutreffend)
DEVICE_REGISTER = 0x00  # Beispielregister

# Funktion zum Lesen von Daten
def read_i2c_data(bus_number, device_address, register, length):
    try:
        with SMBus(bus_number) as bus:
            # Lies `length` Bytes vom angegebenen Register
            data = bus.read_i2c_block_data(device_address, register, length)
        #print(f"Received data: {data}")
        return data
    except Exception as e:
        print(f"Error reading data: {e}")

# Funktion zum Schreiben von Daten
def write_i2c_data(bus_number, device_address, register, data):
    try:
        with SMBus(bus_number) as bus:
            # Schreibe die Daten an das angegebene Register
            bus.write_i2c_block_data(device_address, register, data)
        #print(f"Data {data} written to device at register {register}.")
    except Exception as e:
        print(f"Error writing data: {e}")

# Beispielaufrufe
if __name__ == "__main__":
    BUS_NUMBER = 1  # I2C-Busnummer (oft 1 auf modernen Geräten)
    
    rxdata=read_i2c_data(BUS_NUMBER,0x20,0x00,2)
    print(hex(rxdata[0]<<8 | rxdata[1]))
    
    # Schreibe [0x01, 0x02, 0x03] an das Gerät
    write_i2c_data(BUS_NUMBER, 0x15, 0x45, [0xFF])
    write_i2c_data(BUS_NUMBER, 0x15, 0x02, [0x55])
