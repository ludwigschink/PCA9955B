# PCA9955B
A C++ class for universal using of PCA9955B on multiple platforms.

Using: The idea is to have a software module for universal using of the PCA9955B LED driver.
The hardware abstraction is ensured due providing an access method or function for the PCA9955B class
to access the i2c bus.
Copy the files

PCA9955B_Base.h
PCA9955B_Base.cpp

in your project directory and inherit from class 'PCA9955B_Base'. Dont forget to pass the i2c-dev address
(address only, without read/write bit) to the constructor of PCA9955B_Base class. When inheriting, you
provide the hardware access by declaring a method in the new class 'i2crRXTX' equal to the 'i2cRXTX' method
in the PCA9955B_Base class, where its decalred 'virtual'. By doing that, you overwrite that method and the
PCA9955B_Base class now uses that method.

If not sure how to use it all, consider the files

PCA9955B.h
PCA9955B.cpp

in this repository. They are created as an example and of course for testing this piece of software on a Raspberry
Pi 3B+.

#Tested:
- on Raspberry Pi 3B+
