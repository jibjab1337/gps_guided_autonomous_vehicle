# gps_guided_autonomous_vehicle
A project on a small autonomous vehicle guided by GPS and compass which can avoid small simple objects

Version 1 - Added functionality through text menu to allow multiple destinations (up to 4)
Text menu is through Serial monitor which on the vehicle goes to Serial port 2 through the HM-10 Bluetooth module

Note: The turns must be calibrated by changing the inputs into the delay() functions of the movements. This is up to your own discretion depending on your environment and wheels


Libraries used:
TinyGPS++ 
Arduino-HMC5883L-master Version: 1.1.0 (c) 2014 Korneliusz Jarzebski: https://github.com/jarzebski/Arduino-HMC5883L/blob/master/HMC5883L.h
SoftwareSerial.h
Wire.h
math.h



Materials/Equipment used in this project:
Arduino Mega
Small RC Car chassis/body with four DC motor wheels - Geared Motor DC 6V/200RPM (Any universal 6V DC motor from an RC car will do)
L298N Motor Driver
12 V Battery Supply (I used two battery holder cases in series, four AA 1.5 V batteries each, eight total. You are free to substitute your own 12 V power supply)
Bluetooth: HM-10 BLE Bluetooth 4.0
Compass: GY-271 QMC5883L or HMC5883L (My model was the HMC - this is important because the models use two different I2C addresses and the following code uses HMC)
GPS: NEO 6M V2 + small ceramic antenna (I bought mine on Amazon)
Ultrasonic sensors: HC-SR04 (Three total)
Green LED light
300 Ohm resistor
Breadboard jumper wires and a breadboard (you are free to solder the cables)

Smartphone Application used with Bluetooth: "Serial Bluetooth Terminal" by Kai Morich on Google Play Store





Wiring

Arduino Mega GND is connected to Negative end of 12 V Power Supply of batteries

4 DC Motors

Two left wheels: Positive wires are connected together. Negative wires connected together
MOTOR A side
Positive wire --> OUT1 on L298N motor driver
Negative wire --> OUT2 on L298N motor driver

MOTOR B side
Two right wheels: Positive wires are connected together. Negative wires connected together
Positive wire --> OUT3 on L298N motor driver
Negative wire --> OUT4 on L298N motor driver

L298N Motor Driver
OUT1,2 --> Two left wheels (MOTOR A)
OUT3,4 --> Two right wheels (MOTOR B)
12V --> Connected to Positive end of 12 V Power Supply of batteries
GND --> Connected to Arduino Mega GND

ENA --> Digital Pin 11
IN1 --> Digital Pin 10
IN2 --> Digital Pin 9
IN3 --> Digital Pin 8
IN4 --> Digital Pin 13
ENB --> Digital Pin 12

Ultrasonic sensors (A1,2,3,4,5 are analog pins)
    All of them
VCC - 5 V on Arduino Mega
GND - Arduino Mega GND

Ultrasonic front
TRIG --> A4
ECHO --> A5

Ultrasonic left
TRIG --> A2
ECHO --> A3

Ultrasonic right
TRIG --> A0
ECHO --> A1

Interrupt Pin 2
Digital Pin 2 --> 300 Ohm resistor --> (Anode +) Green LED (Cathode -) --> Arduino Mega GND

GPS
VCC --> 3.3 V on Arduino Mega
GND --> Arduino Mega GND
TX --> Digital Pin 15 
RX --> Digital Pin 14

Bluetooth
VCC --> 3.3 V on Arduino Mega
GND --> Arduino Mega GND
TX --> Digital Pin 17
RX --> Digital Pin 16

Compass
VCC --> 3.3 V on Arduino Mega
GND --> Arduino Mega GND
SCL --> Digital Pin 21
SCA --> Digital Pin 20
