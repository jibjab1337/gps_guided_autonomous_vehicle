void compassBearingDegrees() {  // The function that updates our current compass bearing

  Vector norm = compass.readNormalize();
  float heading = atan2f(norm.YAxis, norm.XAxis); // Calculate heading // atan2
  /*
    You can find declination on: http://magnetic-declination.com/
    (+) Positive or (-) for negative
      For Bytom / Poland declination angle is 4'26E (positive); + 4 = deg, 26 = min
      Formula: (deg + (min / 60.0)) / (180 / M_PI);
      For Los Angeles / USA declination angle is + 11 = deg, 38 = min
  */
  float declinationAngle = (11.0 + (38.0 / 60.0)) / (180 / M_PI);
  heading += declinationAngle;

  if (heading < 0) { // Correct for heading < 0 deg and heading > 360 deg
    heading += 2 * PI;
  }
  if (heading > 2 * PI) {
    heading -= 2 * PI;
  }
  // headingDegrees is now a global so you can use it to compare to gpsAngleDegrees
  headingDegrees = heading * 180 / M_PI; // Convert to degrees

  Serial2.print("Current Compass Degrees = ");
  Serial2.println(headingDegrees);

}