void obstacleAvoid(float lat1, float long1, float lat2, float long2) {          // The function that will perform obstacle avoidance operations after ISR flag is raised
  // obstacleAvoid must go AFTER ultrasonicCheck() in loop()

  // At this point: objectDetected == true and digital pin 2 LED == HIGH
  // So now we find the space for the vehicle to move to

  // The process is the same for every if statement in this function

  // -- MOVEMENT CODE: 90 DEGREE TURNS BELOW -- //
  if ( leftSensor <= 40 && rightSensor > 40 && frontSensor <= 16 ) {
    /*
      if the distance in front is less than or equal to 16 cm,
      and the distance to right is greater than 40 cm and the distance
      to left is less than or equal to 40 cm...
      ...then go right
    */
    rightTurnTimed(1500);                   // Turn right for 1500 milliseconds (adjust when needed)
    goStraightShortDistance(1500);        // Go straight for 1.5 seconds to move away from the obstacle
    compassBearingDegrees();              // Take in your current compass bearing
    GPSTelemetry();                       // Save your new current/updated GPS coordinates
    GPSBearingAngle(lat1, long1, lat2, long2);                    // Calculate the new angle to get to the destination
    correctBearingTurn();                 // Perform a correction to bearing to face the destination again
    digitalWrite(interruptPinTwo, LOW);   // If we get to this point, we avoided the obstacle and can turn off LED
  }                                       // in order to reset the ISR. ISR only activates on RISING in pin 2 (LOW to HIGH)

  if ( leftSensor > 40 && rightSensor > 40 && frontSensor <= 16 ) {
    /*
      if the distance front is less than or equal to 16 cm,
      the distance to the right is greater than 40 cm and the distance
      the left is larger than 40 cm it calls the dir function();
    */
    rightTurnTimed(1500);
    goStraightShortDistance(1500);
    compassBearingDegrees();
    GPSTelemetry();
    GPSBearingAngle(lat1, long1, lat2, long2);
    correctBearingTurn();
    digitalWrite(interruptPinTwo, LOW);
  }

  if ( rightSensor <= 40 && leftSensor > 40 && frontSensor <= 16 ) {
    /*
      if the distance front is less than or equal to 16 cm,
      the distance to the right is less than or equal to 40 cm and the distance
      the left is greater than 40 cm it calls the function left90();
    */
    leftTurnTimed(1600);
    goStraightAfterObstacle(1500);
    compassBearingDegrees();
    GPSTelemetry();
    GPSBearingAngle(lat1, long1, lat2, long2);
    correctBearingTurn();
    digitalWrite(interruptPinTwo, LOW);
  }

  if ( rightSensor <= 40 && leftSensor > 40 && frontSensor > 16 ) {
    leftTurnTimed(1600);
    goStraightAfterObstacle(1500);
    compassBearingDegrees();
    GPSTelemetry();
    GPSBearingAngle(lat1, long1, lat2, long2);
    correctBearingTurn();
    digitalWrite(interruptPinTwo, LOW);
  }

  if ( rightSensor > 40 && leftSensor <= 40 && frontSensor > 16 ) {
    rightTurnTimed(1500);
    goStraightAfterObstacle(1500);
    compassBearingDegrees();
    GPSTelemetry();
    GPSBearingAngle(lat1, long1, lat2, long2);
    correctBearingTurn();
    digitalWrite(interruptPinTwo, LOW);
  }

}
