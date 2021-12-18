void activateObjectAvoid() {  // The ISR that will allow us to go to objectAvoid()
  objectDetected = true;      // ISR will change this bool to true in order to break out of
}                             // the while loop in automation() - IMPORTANT