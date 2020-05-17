# Lab 4
The goal for this lab is to design and implement a home management system using Cortex-M4. There are two parts to this system:

* Part A: Basic system comprising of the base functionality
* Part B: Extra functionality, you can add extra features to enhance the system.

## Part A

* Every second, the system status parameters will be sent out via UART for monitoring. This is the humidity, light status, fan status, etc.

* Light switch works in toggle mode, i.e. press ON/OFF.

* Fan switch works in toggle mode, i.e. press ON/OFF.

* If humidity is above a certain threshold, the fan will turn on.

* Through UART, the light can be turned on and off. If the light turn on/off command and light switch happen in the same time, the UART has the priority. Same goes for the FAN. This is all done within 1 second.

### Cortex M4 Interfaces
```
The Humidity Sensor ------- ADC1 IN0 ( PortA Pin0)
The light ----------------- GPIOB Pin8 ( 0 for ON, 1 for OFF)
The Fan ------------------- GPIOF  Pin8 ( 0 for ON, 1 for OFF)
Light Switch -------------- GPIOB Pin0 ( 0 for pressed, 1 for un-pressed)
Fan Switch ---------------- GPIOB Pin1 ( 0 for pressed, 1 for un-pressed)
Serial Port --------------- USART6 ( PortC pin6 ---TX, PortC pin7---RX)
```

