// analogWrite() uses PWM values from 0 to 255

void DCMotorZero() {            // The function that turns off the motors. dcmotoZero() must go after ultrasonicCheck()
  analogWrite(L_motors_speed, 0);
  analogWrite(R_motors_speed, 0);

  analogWrite(L1, 0);
  analogWrite(L2, 0);
  analogWrite(R1, 0);
  analogWrite(R2, 0);
}

void goReverseShortDistance( int duration ) {   // The function that makes us go in reverse for specified duration

  analogWrite(L_motors_speed, 153); // 60, 100
  analogWrite(R_motors_speed, 153);

  analogWrite(L1, 0);
  analogWrite(L2, 255);
  analogWrite(R1, 255);
  analogWrite(R2, 0);
  delay(duration);

}

void goStraightShortDistance( int duration ) {  // The function that makes us go straight for specified duration

  analogWrite(L_motors_speed, 153); // 60, 100 // THESE COMMANDS MAKE ROBOT GO STRAIGHT
  analogWrite(R_motors_speed, 153); // 153    // RIGHT HAS MORE TORQUE THAN LEFT

  analogWrite(L1, 255); // 204
  analogWrite(L2, 0);
  analogWrite(R1, 0);
  analogWrite(R2, 255); // 255 // 204
  delay(duration);

}

void goStraightAfterObstacle( int duration ) {  // The function that makes us go straight after turning away from obstacle

  analogWrite(L_motors_speed, 220); // 51, 102
  analogWrite(R_motors_speed, 220);

  analogWrite(L1, 255); // 204
  analogWrite(L2, 0);
  analogWrite(R1, 0);
  analogWrite(R2, 255); // 255 // 204
  delay(duration);

}

void leftTurnTimed( int duration ) {              // The function to make the robot turn left for specified duration

  analogWrite(L_motors_speed, 220);  // 120 // 204
  analogWrite(R_motors_speed, 220); // 120

  analogWrite(L1, 0);     // 0
  analogWrite(L2, 255);   // 255
  analogWrite(R1, 0);     // 0
  analogWrite(R2, 255);   // 255
  delay(duration);        // 700

}

void rightTurnTimed( int duration ) {             // The function to make the robot turn right for specified duration

  analogWrite(L_motors_speed, 220);  // 120 // 204
  analogWrite(R_motors_speed, 220); // 120

  analogWrite(L1, 255); // 255
  analogWrite(L2, 0);   // 0
  analogWrite(R1, 255); // 255
  analogWrite(R2, 0);   // 0
  delay(duration);      // 800

}

void stopCar() {                                // The function that stops car for a long delay (100 seconds)

  analogWrite(L_motors_speed, 0);
  analogWrite(R_motors_speed, 0);

  analogWrite(L1, 0); // 0
  analogWrite(L2, 0); // 0
  analogWrite(R1, 0); // 0
  analogWrite(R2, 0); // 0
  delay(100000); // Stop car for one hundred seconds
  // WE ARE DONE IF WE REACH THIS POINT!!!

}

void stopCarTimed( int duration ) {             // Stop the car for a specified duration. Useful for delays

  analogWrite(L_motors_speed, 0);
  analogWrite(R_motors_speed, 0);

  analogWrite(L1, 0);
  analogWrite(L2, 0);
  analogWrite(R1, 0);
  analogWrite(R2, 0);
  delay(duration);                              // Stop car for amount of duration

}
