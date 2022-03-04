# PCA9955B
A C++ class for universal using of PCA9955B on multiple platforms.

Using: The idea is to have a software module for universal platforms (e.g. microcontroller, raspberry etc) of the PCA9955B LED driver.
The hardware abstraction is ensured due providing a method or function for the PCA9955B class to access the i2c bus.

## Deploy
Simply move the files

PCA9955B_Base.h <br>
PCA9955B_Base.cpp <br>

in your project directory. 

## Using
Create a new class and inherit from class 'PCA9955B_Base'.
Dont forget to pass the i2c-dev address (address only, without read/write bit)
to the constructor of PCA9955B_Base class. When inheriting, you provide the hardware access by declaring
a method in the new class 'i2crRXTX' equal to the 'i2cRXTX' method in the PCA9955B_Base class, where its
declared 'virtual'. By doing that, you overwrite that method and the PCA9955B_Base class now uses that
method.<br>

Important: - You may have to kill all pigpiod deamons, because it prevents pigpio to be initialized.<br>
		   - because of the pigpio library, you have to run it with sudo rights.<br>

If not sure how to use it all, consider the files

PCA9955B.h <br>
PCA9955B.cpp <br>

in this repository. They are created as an example and of course for testing this piece of software on a Raspberry
Pi 4B+. You can open the geany project by loading the project file 'PCA9955B.geany' in geany. You may have to rename
the project directory in 'preferences'. Then run 'cmake' under the tab 'Make' and then you can make the whole program
with 'Make' under the tab 'Make' or simply hit shift+F9.

#Tested:
- on Raspberry Pi 4B+
