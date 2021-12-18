# gps_guided_autonomous_vehicle
A project on a small autonomous vehicle guided by GPS and compass which can avoid small simple objects<br />
<br />
Input one or multiple destinations manually through a text menu on a Bluetooth terminal and the vehicle will move to its destination<br />
Comes with basic obstacle avoidance maneuver<br />
<br />
![alt text](https://github.com/jibjab1337/gps_guided_autonomous_vehicle/blob/main/Final%20design.jpg)
<br />
## Version 1 - Added functionality through text menu to allow multiple destinations (up to 4)<br />
Text menu is through Serial monitor which on the vehicle goes to Serial port 2 through the HM-10 Bluetooth module<br />
<br />
Note: The turns must be calibrated by changing the inputs into the delay() functions of the movements. This is up to your own discretion depending on your environment and wheels<br />
<br />
<br />
<br />
<br />
<br />
## Libraries used:
TinyGPS++ <br />
Arduino-HMC5883L-master Version: 1.1.0 (c) 2014 Korneliusz Jarzebski: https://github.com/jarzebski/Arduino-HMC5883L/blob/master/HMC5883L.h<br />
SoftwareSerial.h<br />
Wire.h<br />
math.h<br />
<br />
<br />
<br />
<br />
<br />
## Materials/Equipment used in this project:<br />
Arduino Mega<br />
Small RC Car chassis/body with four DC motor wheels - Geared Motor DC 6V/200RPM (Any universal 6V DC motor from an RC car will do)<br />
L298N Motor Driver<br />
12 V Battery Supply (I used two battery holder cases in series, four AA 1.5 V batteries each, eight total. You are free to substitute your own 12 V power supply)<br />
Bluetooth: HM-10 BLE Bluetooth 4.0<br />
Compass: GY-271 QMC5883L or HMC5883L (My model was the HMC - this is important because the models use two different I2C addresses and the following code uses HMC)<br />
GPS: NEO 6M V2 + small ceramic antenna (I bought mine on Amazon)<br />
Ultrasonic sensors: HC-SR04 (Three total)<br />
Green LED light<br />
300 Ohm resistor<br />
Breadboard jumper wires and a breadboard (you are free to solder the cables)<br />
<br />
You need a smartphone or a virtual machine on your computer for Android in order to wirelessly communicate with the vehicle<br />
Smartphone Application used with Bluetooth: "Serial Bluetooth Terminal" by Kai Morich on Google Play Store<br />
<br />
<br />
<br />
<br />
<br />
## Wiring<br />
<br />
Arduino Mega GND is connected to Negative end of 12 V Power Supply of batteries<br />
<br />
4 DC Motors<br />
<br />
Two left wheels: Positive wires are connected together. Negative wires connected together<br />
MOTOR A side<br />
Positive wire --> OUT1 on L298N motor driver<br />
Negative wire --> OUT2 on L298N motor driver<br />
<br />
MOTOR B side<br />
Two right wheels: Positive wires are connected together. Negative wires connected together<br />
Positive wire --> OUT3 on L298N motor driver<br />
Negative wire --> OUT4 on L298N motor driver<br />
<br />
L298N Motor Driver<br />
OUT1,2 --> Two left wheels (MOTOR A)<br />
OUT3,4 --> Two right wheels (MOTOR B)<br />
12V --> Connected to Positive end of 12 V Power Supply of batteries<br />
GND --> Connected to Arduino Mega GND<br />
<br />
ENA --> Digital Pin 11<br />
IN1 --> Digital Pin 10<br />
IN2 --> Digital Pin 9<br />
IN3 --> Digital Pin 8<br />
IN4 --> Digital Pin 13<br />
ENB --> Digital Pin 12<br />
<br />
Ultrasonic sensors (A1,2,3,4,5 are analog pins)<br />
    All of them<br />
VCC - 5 V on Arduino Mega<br />
GND - Arduino Mega GND<br />
<br />
Ultrasonic front<br />
TRIG --> A4<br />
ECHO --> A5<br />
<br />
Ultrasonic left<br />
TRIG --> A2<br />
ECHO --> A3<br />
<br />
Ultrasonic right<br />
TRIG --> A0<br />
ECHO --> A1<br />
<br />
Interrupt Pin 2<br />
Digital Pin 2 --> 300 Ohm resistor --> (Anode +) Green LED (Cathode -) --> Arduino Mega GND<br />
<br />
GPS<br />
VCC --> 3.3 V on Arduino Mega<br />
GND --> Arduino Mega GND<br />
TX --> Digital Pin 15 <br />
RX --> Digital Pin 14<br />
<br />
Bluetooth<br />
VCC --> 3.3 V on Arduino Mega<br />
GND --> Arduino Mega GND<br />
TX --> Digital Pin 17<br />
RX --> Digital Pin 16<br />
<br />
Compass<br />
VCC --> 3.3 V on Arduino Mega<br />
GND --> Arduino Mega GND<br />
SCL --> Digital Pin 21<br />
SCA --> Digital Pin 20<br />
<br />
