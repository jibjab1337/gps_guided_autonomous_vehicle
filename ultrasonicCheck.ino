void ultrasonicCheck() {        // The function that will save ultrasonic data from the three sensors

  // long front_Duration, left_Duration, right_Duration, right, left, front;  THESE ARE NOW GLOBALS

  digitalWrite(frontSent, LOW);                     // The respective signal inputs and outputs of the
  delayMicroseconds(2);                             // ultrasonic sensor and stored by the sensor variables
  digitalWrite(frontSent, HIGH);                    // which converts the speed of sound - 340 m/s or
  delayMicroseconds(5);                             // 29 microseconds per centimeter - as the signal goes back and forth
  digitalWrite(frontSent, LOW);                     // The time is halved due to travel time, thus sensor = time / 29 / 2 ;
  frontTime = pulseIn(frontReceive, HIGH);          // Same process for the other sensors.
  frontSensor = frontTime / 29 / 2;

  digitalWrite(leftSent, LOW);
  delayMicroseconds(2);
  digitalWrite(leftSent, HIGH);
  delayMicroseconds(5);
  digitalWrite(leftSent, LOW);
  leftTime = pulseIn(leftReceive, HIGH);
  leftSensor = leftTime / 29 / 2;

  digitalWrite(rightSent, LOW);
  delayMicroseconds(2);
  digitalWrite(rightSent, HIGH);
  delayMicroseconds(5);
  digitalWrite(rightSent, LOW);
  rightTime = pulseIn(rightReceive, HIGH);
  rightSensor = rightTime / 29 / 2;

}
