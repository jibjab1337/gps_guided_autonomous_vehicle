# gps_guided_autonomous_vehicle
An Arduino project on a small autonomous vehicle guided by GPS and compass which can avoid small simple objects<br />
<br />
Input one or multiple destinations manually through a text menu on a Bluetooth terminal and the vehicle will move to its destination<br />
Comes with basic obstacle avoidance maneuver<br />
<br />
This is the final design of the vehicle<br />
![alt text](https://github.com/jibjab1337/gps_guided_autonomous_vehicle/blob/main/Final%20design.jpg)
<br />
Please note the placement of each component, especially the digital magnetometer. The digital magnetometer must be placed at least 15 cm away from the other components due to it being very sensitive to electrical components such as the motor driver and power supply - hence why it is on a makeshift small cardboard tower.<br />

## How it works<br />
1. Turn on the vehicle and connect to the Bluetooth on your smartphone. You will know you are connected if you see the text menu appear<br />
2. Enter character commands in the Bluetooth app as well as your GPS coordinates (up to 6 decimal places)<br />
3. Once you've entered your coordinates, you will be taken to another text menu with options to move the vehicle and automation. You must test the turns of your vehicle and change the millisecond inputs to ALL the turns since all turns and movements have hardcoded millisecond inputs.<br />
4. If you're satisfied with the turns and movements of your own vehicle, proceed to the automation option<br />
5. The vehicle should then begin turning towards its destination<br />
6. If the vehicle is not facing within 10 degrees of its destination, it will correct itself. Please note that these turn corrections must be short, quick turns and thus it is up to you to hardcode the specific millisecond inputs - if your turns are too wide or too short, the vehicle will take longer to move to its destination<br />
7. If the vehicle detects a small simple object in front of its sensors, it will proceed to turn on an LED connected to pin 2 and do a short turn. After the turn, it will correct its bearing and proceed again towards its destination<br />
8. Once the vehicle detects that it's within 3 meters of its destination (this distance is chosen because it is fairly common with GPS to have a small radius of inaccuracy) it will stop and tell you through text that you have arrived. It will then print out its final GPS coordinates.<br />


## Important notes<br />
1. This project only works on a large, flat open area outdoors. I would try this vehicle project in a large open parking lot with smooth pavement. You could in theory use a higher-end RC car model and rig it to the specifications outlined in this project but I used a very cheap 20 dollar generic DIY RC car model.<br />
2. You must stay 10-20 feet or 3-6 meters of the vehicle in order to constantly see the stream of data through Bluetooth. You might occassionally disconnect from Bluetooth but I would always connect back quickly and still receive data<br />
3. Obstacle avoidance is very basic - the vehicle can avoid small flat object in front of its sensors. Only use small flat objects as obstacles so that the ultrasonic sensors can receive the sound wave bounces properly.<br />
4. Calibrate the compass. It is very important that the digital magnetometer is calibrated correctly. Please use the code from the specific arduino library I linked as it contains calibration code. If you're using the Arduino IDE, calibration code can be found in "File > Examples > Arduino-HMC5883L-master > HMC5883L_calibrate"<br />
5. Digital magnetometer must be placed 15 cm away from any electrical component of the vehicle. I chose to put it on a makeshift 20 cm tall tower. If you don't do this, you will not get proper angles from the compass. Also, the model I bought is very sensitive to its environment; I would test out the compass in different areas of my college campus and would find that the compass just did not work in specific areas. All angles in this project range from 0.00 to 359.99 degrees with 0 degrees being north, 90 degrees being east, 180 degrees being south, 270 degrees being west and 359.99 degrees being north again. To test if you calibrated your compass correctly, pick up the vehicle and have it face the general direction of true north, south, east, west and see if the angle bearing values closely match the numbers I outlined.<br />


Example of the text menu ran through the Bluetooth App on Android<br />
![alt text](https://github.com/jibjab1337/gps_guided_autonomous_vehicle/blob/main/Bluetooth_Serial_Monitor_Text_Menu.jpg)
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
Small RC Car chassis/body with four DC motor wheels - Geared Motor DC 6V / 200 RPM (Any universal 6V DC motor from a generic RC car will do)<br />
L298N Motor Driver<br />
12 V Battery Supply - Used two battery holder cases in series, four AA 1.5 V batteries each, eight total. Feel free to substitute your own 12 V power supply<br />
Bluetooth: HM-10 BLE Bluetooth 4.0<br />
Compass: GY-271 QMC5883L or HMC5883L - Model was the HMC - this is important because the models use two different I2C addresses and the following code uses HMC<br />
GPS: NEO 6M V2 + small ceramic antenna - Bought mine on Amazon<br />
Ultrasonic sensors: HC-SR04 (Three total)<br />
Green LED light - Any generic LED will do, it doesn't have to be green<br />
300 Ohm resistor<br />
Breadboard jumper wires and a breadboard -feel free to solder the cables<br />
<br />
You need a smartphone or a virtual machine on your computer for Android in order to wirelessly communicate with the vehicle<br />
Smartphone Application used with Bluetooth: "Serial Bluetooth Terminal" by Kai Morich on Google Play Store<br />
I use Android and this application works well. If you're on Apple, you're going to have to find another Bluetooth app<br />
<br />
<br />
<br />
<br />
<br />
## Wiring<br />
<br />
Arduino Mega GND is connected to Negative end of 12 V Power Supply of batteries<br />
<br />
4 DC Motors -> L298N Motor Driver<br />
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
