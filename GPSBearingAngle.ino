void GPSBearingAngle(float lat1, float long1, float lat2, float long2) {        // The function that calculates the angle to destination
                                // given our updated current GPS coordinates
  float y_angle = cosf(lat2) * sinf(long2 - long1);
  float x_angle = (cosf(lat1) * sinf(lat2)) - (sinf(lat1) * cosf(lat2) * cosf(long2 - long1));

  float gpsAngleRads = atan2f(y_angle, x_angle);                                // Angle is in radians
  float gpsAngleDegreesFloat = ( 360.00 + ( ( 180 / M_PI ) * gpsAngleRads ) );  // convert radians to degrees

  gpsAngleDegrees = fmod(gpsAngleDegreesFloat, 360.00);

  gpsAngleDegrees = 360.00 - gpsAngleDegrees;

  Serial2.print("NEW Angle in degrees to point B = ");
  Serial2.println(gpsAngleDegrees);

}
