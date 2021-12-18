void IsCarFacingDestination() { // The function that checks if we're facing our destination

  if ( (headingDegrees <= (gpsAngleDegrees + 10.00)) && (headingDegrees >= (gpsAngleDegrees - 10.00)) ) {

    // If our compass angle is within + / - 10 degrees of our destination bearing angle
    // we are facing the right direction and thus we go straight for a short distance

    stopCarTimed(10);                 // Stop motors briefly
    GPSTelemetry();                   // Update current GPS coordinates
    goStraightShortDistance(300);     // go straight for 300 milliseconds

  }
  else {

    // Else, the compass is not pointed within + / - 10 degrees of the destination

    Serial2.println("You are not pointed in the direction of your destination. Correcting bearing.");
    stopCarTimed(10);
    GPSTelemetry();
    correctBearingTurn(); // We must correct our current bearing so we call this function
  }

}
