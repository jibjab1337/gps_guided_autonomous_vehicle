void multipleDestinations() {           // The menu that will run infinitely in the loop()

  char g;
  bool Quit = false;

  Serial2.println("Multiple Destinations Menu");
  Serial2.println("The vehicle can travel up to three destinations in sequential order: Destination 1 --> 2 --> 3");
  delay(1000);
  Serial2.println("Please input up to THREE destinations (latitude, longitude) when prompted.");
  delay(1000);
  Serial2.println("Warning: Coordinates will be off by a very small amount due to Arduino limitations with float precision");
  Serial2.println("Please enter one of the following numbers or characters to access each option");
  Serial2.println("Note: Enter 'd' to display menu options");
  delay(1000);
  Serial2.println("'1': Destination 1   '2': Destination 2   '3': Destination 3   ");
  Serial2.println("'e': Exit menu   's': Show destinations   'd': Display options");
  delay(50);

  while (!Quit) {                   // As long as Quit isn't true, this switch/case menu will run infinitely
    if (Serial2.available() > 0) {
      g = Serial2.read();
      switch (g) {
        case '1':     // Destination 1
          Serial2.println("Input your first destination latitude coordinate: ");
          latitB = stringToFloatConversion();
          Serial2.println("Input your first destination longitude coordinate: ");
          lonB = stringToFloatConversion();
          delay(50);
          Serial2.println("Your first destination coordinate is: ");
          Serial2.print("Latitude: ");
          Serial2.println(latitB, 6);
          Serial2.print("Longitude: ");
          Serial2.println(lonB, 6);
          break;
        case '2':     // Destination 2
          Serial2.println("Input your second destination latitude coordinate: ");
          latitC = stringToFloatConversion();
          Serial2.println("Input your second destination longitude coordinate: ");
          lonC = stringToFloatConversion();
          delay(50);
          Serial2.println("Your second destination coordinate is: ");
          Serial2.print("Latitude: ");
          Serial2.println(latitC, 6);
          Serial2.print("Longitude: ");
          Serial2.println(lonC, 6);
          break;
        case '3':     // Destination 3
          Serial2.println("Input your third destination latitude coordinate: ");
          latitD = stringToFloatConversion();
          Serial2.println("Input your third destination longitude coordinate: ");
          lonD = stringToFloatConversion();
          delay(50);
          Serial2.println("Your third destination coordinate is: ");
          Serial2.print("Latitude: ");
          Serial2.println(latitD, 6);
          Serial2.print("Longitude: ");
          Serial2.println(lonD, 6);
          break;
        case 'e':     // Letter e
          Serial2.println("Exiting the Multiple Destinations menu.");   // Quit the menu
          Quit = true;
          break;
        case 's':     // Letter s
          Serial2.println("These are your current destinations");
          Serial2.println("Your first destination coordinate is: ");
          Serial2.print("Latitude: ");
          Serial2.println(latitB, 6);
          Serial2.print("Longitude: ");
          Serial2.println(lonB, 6);
          delay(50);
          Serial2.println("Your second destination coordinate is: ");
          Serial2.print("Latitude: ");
          Serial2.println(latitC, 6);
          Serial2.print("Longitude: ");
          Serial2.println(lonC, 6);
          delay(50);
          Serial2.println("Your third destination coordinate is: ");
          Serial2.print("Latitude: ");
          Serial2.println(latitD, 6);
          Serial2.print("Longitude: ");
          Serial2.println(lonD, 6);
          break;
        case 'd':     // Letter d
          Serial2.println("Displaying Multiple Destinations Menu options");
          Serial2.println("Multiple Destinations Menu");
          Serial2.println("The vehicle can travel up to three destinations in sequential order: Destination 1 --> 2 --> 3");
          delay(1000);
          Serial2.println("Please input up to THREE destinations (latitude, longitude) when prompted.");
          delay(1000);
          Serial2.println("Warning: Coordinates will be off by a very small amount due to Arduino limitations with float precision");
          Serial2.println("Please enter one of the following numbers or characters to access each option");
          Serial2.println("Note: Enter 'd' to display menu options");
          delay(1000);
          Serial2.println("'1': Destination 1   '2': Destination 2   '3': Destination 3   ");
          Serial2.println("'e': exit menu   's': Show destinations   'd': Display options");
          delay(50);
          break;
      }
      delay(50);
    }
  }
}

/*
  void multipleDestinations() {
  char f;
  bool Quit = true;

  while ( Quit == true ) {
    Serial2.println("Multiple Destinations Menu");
    Serial2.println("Please input three destinations (latitude, longitude) when prompted.");
    Serial2.println("Warning: Coordinates will be off by a very small amount due to Arduino limitations with float precision");
    delay(2000);

    Serial2.println("Input your first destination latitude coordinate: ");
    latitB = stringToFloatConversion();
    Serial2.println("Input your first destination longitude coordinate: ");
    lonB = stringToFloatConversion();
    Serial2.println("Input your second destination latitude coordinate: ");
    latitC = stringToFloatConversion();
    Serial2.println("Input your second destination longitude coordinate: ");
    lonC = stringToFloatConversion();
    Serial2.println("Input your third and final destination latitude coordinate: ");
    latitD = stringToFloatConversion();
    Serial2.println("Input your third and final destination longitude coordinate: ");
    lonD = stringToFloatConversion();

    delay(1000);

    Serial2.println("Your first destination coordinate is: ");
    Serial2.print("Latitude: ");
    Serial2.println(latitB, 6);
    Serial2.print("Longitude: ");
    Serial2.println(lonB, 6);

    Serial2.println("Your second destination coordinate is: ");
    Serial2.print("Latitude: ");
    Serial2.println(latitC, 6);
    Serial2.print("Longitude: ");
    Serial2.println(lonC, 6);

    Serial2.println("Your third and final destination coordinate is: ");
    Serial2.print("Latitude: ");
    Serial2.println(latitD, 6);
    Serial2.print("Longitude: ");
    Serial2.println(lonD, 6);

    Serial2.println("Are these destinations correct?   'y': yes   'n': no   ");  // This checks if our data is correct
    while (Serial2.available() == 0) {}                                       // Wait for user input in terminal
    f = Serial2.read();
    if (f == 'y') {                                                           // If our destination coordinates are correct
      Serial2.println("Destinations have been confirmed. Proceeding to main menu.");
      Quit = false;                                                           // ...we can quit the menu by breaking out of
    }                                                                         // the entire while loop (and function)
    else if (f == 'n') {                                                      // Else, we stay in the menu until valid coordinates
      Serial2.println("Destination have not been confirmed. Going back to Destination menu");
    }
    else {
      Serial2.println("Input isn't clear. Going back to Destination menu");
    }

  }

  }
*/
