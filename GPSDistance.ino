float GPSDistance (float lat1, float long1, float lat2, float long2) { // The function that does the actual GPS distance calculation
                                                                        // using updated GPS coordinates and destination coordinates
  float delta = radians(long1 - long2);                                 
  float sdlong = sin(delta);
  float cdlong = cos(delta);

  lat1 = radians(lat1);
  lat2 = radians(lat2);

  float slat1 = sin(lat1);
  float clat1 = cos(lat1);

  float slat2 = sin(lat2);
  float clat2 = cos(lat2);

  delta = (clat1 * slat2) - (slat1 * clat2 * cdlong);
  delta = sq(delta);
  delta += sq(clat2 * sdlong);
  delta = sqrt(delta);

  float denom = (slat1 * slat2) + (clat1 * clat2 * cdlong);
  delta = atan2(delta, denom);

  return delta * 6372795;                                                 // Returns the distance. We set this equal to a variable and insert in
} 
