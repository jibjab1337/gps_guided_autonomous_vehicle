void correctBearingTurn() {
  
  // Global variables used from other functions
  // headingDegrees = Our compass direction. From compassBearingDegrees() function
  // gpsAngleDegrees = The angle required to face destination. From GPSBearingDegrees() function

  /*
    To make the shortest turn possible, we take our current compass bearing (headingDegrees) and
    the calculated angle to get to destination (gpsAngleDegrees) and we take the difference of the
    two twice (always positive) and compare the difference in degrees between the left and right
    turns in order to make the shortest turn
  */

  float leftDegreeTurn = headingDegrees - gpsAngleDegrees;
  if (leftDegreeTurn <= 0.00) {           // To account for negative degrees, we add 360
    leftDegreeTurn = leftDegreeTurn + 360.00;
  }
  Serial2.println(leftDegreeTurn);

  float rightDegreeTurn = gpsAngleDegrees - headingDegrees;
  if (rightDegreeTurn <= 0.00) {
    rightDegreeTurn = rightDegreeTurn + 360.00;
  }
  Serial2.println(rightDegreeTurn);

  if ( rightDegreeTurn < leftDegreeTurn ) {
    // insert turn function to keep turning until car direction is corrected
    Serial2.println("Correcting heading to the right...");
    stopCarTimed(750);
    rightTurnTimed(150);
  }
  else if ( leftDegreeTurn <= rightDegreeTurn ) {
    // insert turn function to keep turning until car direction is corrected
    Serial2.println("Correcting heading to the left...");
    stopCarTimed(750);
    leftTurnTimed(150);
  }
  else { // nothing

  }

}
