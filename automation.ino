// automation procedures of vehicle

void automation(float lat1, float long1, float lat2, float long2) {             // The main automation function of the car

  while (1) { // To get out of the loop, use break; This loop will simulate loop() so that it runs infinitely
    // until we raise another flag to break out of the entire function when we arrive at our destination
    while (objectDetected == false) {                                   // If we detect no obstacles...
      compassBearingDegrees();                                          // Get your current compass heading
      GPSTelemetry();                                                   // Get your current GPS location
      float checkDistance = GPSDistance(lat1, long1, lat2, long2);      // Input GPS data into distance formula to get distance
      GPSBearingAngle(lat1, long1, lat2, long2);                        // Calculate the angle to get to destination
      checkIfWeArrived( checkDistance );                                // Check if we're near destination by checking distance
      if ( carArrived == true ) {                                       // If we arrived, flag is raised...
        break;                                                          // and we break out of the entire automation() function
      }                                                                 // We go back to MenuFunction() as a result
      IsCarFacingDestination();                                         // If we haven't arrived, check if we're facing destination
      ultrasonicCheck();                                                // Then turn on the ultrasonic sensors of front, left, right
      if ( (frontSensor < 16 ) || (leftSensor < 16) || (rightSensor < 16) ) {   // If front, left, right sensors detect an object 16 cm away
        digitalWrite(interruptPinTwo, HIGH);                // then change the pin 2 LED from LOW to HIGH
                                                            // doing so will get us to objectAvoid() operations
      }                                                     // by calling ISR, raising objectDetected flag and breaking out of
    }                                                       // the inner while loop
    obstacleAvoid(lat1, long1, lat2, long2);                                        // Go to obstacleAvoid() if we break out of inner while loop
    objectDetected = false;                                 // After avoiding obstacle, reset the ISR flag and continue the inner
                                                            // while loop of automation();
  }                                                         // end of while(1) outer loop. Breaking out of the outer while loop ends the entire automation function

}
