#!/bin/bash

i2cset -y 1 0x15 0x45 0xFE
i2cset -y 1 0x15 0x02 0x00
i2cset -y 1 0x15 0x03 0x00
i2cset -y 1 0x15 0x04 0x00
i2cset -y 1 0x15 0x05 0x00

read -p "press any button"
i2cset -y 1 0x15 0x02 0x01
read -p "press any button"
i2cset -y 1 0x15 0x02 0x05
read -p "press any button"
i2cset -y 1 0x15 0x02 0x15
read -p "press any button"
i2cset -y 1 0x15 0x02 0x55
read -p "press any button"
i2cset -y 1 0x15 0x03 0x01
read -p "press any button"
i2cset -y 1 0x15 0x03 0x05
read -p "press any button"
i2cset -y 1 0x15 0x03 0x15
read -p "press any button"
i2cset -y 1 0x15 0x03 0x55
read -p "press any button"
i2cset -y 1 0x15 0x04 0x01
read -p "press any button"
i2cset -y 1 0x15 0x04 0x05
read -p "press any button"
i2cset -y 1 0x15 0x04 0x15
read -p "press any button"
i2cset -y 1 0x15 0x04 0x55
read -p "press any button"
i2cset -y 1 0x15 0x05 0x01
read -p "press any button"
i2cset -y 1 0x15 0x05 0x05
read -p "press any button"
i2cset -y 1 0x15 0x05 0x15