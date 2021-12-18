// setup

void setup() {
  // Initializing the ports needed for all modules
  Serial.begin(9600);                         // Serial0 and Serial3 must have same baud
  HM10.begin(9600);                           // set HM10 serial at 9600 baud rate. Bluetooth is on Serial2 Mega pins 16 and 17
  Serial2.begin(9600);                        // Serial2 will print on Bluetooth app terminal
  Serial3.begin(9600);                        // Use Serial3 for the Mega connections (pin 18, 19)

  Serial2.println("Starting Setup procedures");

  // Initializing the interrupt variables
  pinMode(interruptPinTwo, OUTPUT);     // Set pin mode of pin 2 to output
  digitalWrite(interruptPinTwo, LOW);   // Set LED in pin 2 to LOW to start
  objectDetected = false;               // initialize this bool for the interrupt

  /*
    We want to make an interrupt service routine that toggles bool objectDetected

    To avoid "polling" for obstacle avoidance, we only do so when it is necessary
    to "interrupt" the default path of our car from point A to point B

    When the ultrasonic sensors detect an object near it with one of its sensors
    we want it to quickly change the output of digital pin 2 (shown as an LED)
    and in turn trigger the bool objectDetected to change to true.

    When objectDetected changes to true, we break out of the while loop of automation
    program and go to objectAvoid() operations which will do the actual object
    avoidance functions.

    Once objectAvoid() operations are over, the pin should reset to LOW, the bool
    objectDetected should reset to false and we go back to the main while loop
    program which controls the main operations of the car within automation()

    Remember: the default of our program is to go from point A to point B. If there's
    no objects in its path, it should go in a relatively straight line (with some
    corrections to the steering every now and then due to imperfect motors and friction)

    Object avoidance should only be triggered when necessary
  */

  // Car setup
  pinMode(frontSent, OUTPUT);        // front_Trig arduino signal output
  pinMode(frontReceive, INPUT);         // front_Echo arduino signal input

  pinMode(leftSent, OUTPUT);         // left_Trig arduino signal output
  pinMode(leftReceive, INPUT);          // left_Echo arduino signal input

  pinMode(rightSent, OUTPUT);        // right_Trig arduino signal output
  pinMode(rightReceive, INPUT);         // right_Echo arduino signal input

  pinMode(L_motors_speed, OUTPUT);    // left engine speed arduino signal output
  pinMode(R_motors_speed, OUTPUT);    // Arduino signal output of right engine speed

  pinMode(L1, OUTPUT);  // Arduino signal output from left motor rotation direction control
  pinMode(L2, OUTPUT);  // Arduino signal output from left motor rotation direction control
  pinMode(R1, OUTPUT);  // Arduino signal output from the right engine rotation direction control
  pinMode(R2, OUTPUT);  // Arduino signal output from the right engine rotation direction control

  // Compass Setup
  while (!compass.begin()) {         // Check if compass is being detected
    Serial2.println("Could not find a valid HMC5883L sensor, check wiring!");
    delay(500);                      // Print this every 0.5 seconds while in the loop
  }
  compass.setRange(HMC5883L_RANGE_1_3GA);           // Set compass measurement range
  compass.setMeasurementMode(HMC5883L_CONTINOUS);   // Set compass measurement mode
  compass.setDataRate(HMC5883L_DATARATE_30HZ);      // Set compass data rate // default 30 Hz
  compass.setSamples(HMC5883L_SAMPLES_8);           // Set compass # of samples averaged // default 8

  // Compass Offset IS IMPORTANT. RUN CALIBRATION TESTS FIRST IF YOU'RE RUNNING IN A NEW ENVIRONMENT
  /*
    Using HMC5883L_calibration.ino from the Arduino-HMC5883L-master library, do an offset calibration test
    Offset in VEC Building:   (100, 250)
    Offset at home:           (88, 2), (-80, 50)
  */
  compass.setOffset(25, -175);                      // The default offset found. This works on most environments

  // GPS Coordinates Setup
  /*
    GPS takes a few minutes to power on when powering vehicle for 1st time
    It has no coordinates saved until GPS turns on
    Therefore, we must wait in a while loop until GPS turns on
    and records our current location for the 1st time

    This is essential because otherwise, the vehicle could not have
    initial GPS coordinates to do the proper calculations
  */
  while (latitA == 0.00 && lonA == 0.00) {
    GPSTelemetry();
  }
  //latitB;                 // latitB, lonB are your destination coordinates
  //lonB;                   // They will be inputted from the inputDestination() function

  // Pick RISING for now so that green LED in pin 2 turns on during object avoidance and turns off when done
  // attach the ISR to the changes in pin 2 (shown through a green LED)                 // RISING: LOW to HIGH
  attachInterrupt(digitalPinToInterrupt(interruptPinTwo), activateObjectAvoid, RISING); // RISING, FALLING, CHANGE
  
  inputDestination();       // Go to function to input your destination coordinates
  
  Serial2.println("Setup complete. Car operations will begin in 10 seconds");
  delay(10000);             // 10 seconds - To give us time to prepare the car

}
