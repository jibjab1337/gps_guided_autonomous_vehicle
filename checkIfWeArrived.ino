bool checkIfWeArrived( float checkDistance ) {  // The function that will check if we've arrived
                                                // at our destination
  // Set a bool flag through a global variable
  // carArrived - Our bool global that is set equal to this function

  // If we are within 5 meters of destination, we've arrived and can stop

  if ( checkDistance <= 3.00 ) {  // If distance is less than 3 meters
    Serial2.println("WE ARE WITHIN 3 METERS OF THE DESTINATION! WE HAVE ARRIVED!");
    Serial2.println("Distance to exact destination: ");
    Serial2.println(checkDistance);
    carArrived = true;         // We raise the bool flag carArrived to true
    DCMotorZero();             // Stop car for 100 seconds (but we should just turn off motors w/ no delay() ) // stopCar();
    return carArrived;         // Return the bool carArrived - THIS IS THE 2ND IMPORTANT FLAG OF AUTOMATION
  }
  else {                  // Else, the distance is greater than 3 meters and we have not arrived yet
    carArrived = false;   // carArrived is set to false by default
    return carArrived;
  }

}
