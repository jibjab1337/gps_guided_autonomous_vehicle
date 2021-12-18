void GPSTelemetry() {           // The function that updates our current GPS coordinates once

  stopTelemetry = true;   //stopTelemetry is a global and will end while loop
  while ( Serial3.available() > 0 && stopTelemetry == true ) {

    gps.encode(Serial3.read());

    if (gps.location.isUpdated()) {
      latitA = gps.location.lat();
      lonA = gps.location.lng();
      Serial2.println("Number of Satelites");
      Serial2.println(gps.satellites.value());
      Serial2.println("Current Latitude (latitA)");
      Serial2.println(latitA, 6);
      Serial2.println("Current Longitude (lonA)");
      Serial2.println(lonA, 6);
      stopTelemetry = false; // How we break from the infinite while loop
      // Getting rid of this makes function run infinitely
    }

  }

}
