// Main menu in loop()

void MenuFunction() {           // The menu that will run infinitely in the loop()

  char b, c;
  bool Quit = false;
  // Print statements to show available character options
  Serial2.println("Main Menu");
  Serial2.println("Enter the following lowercase characters for menu options");
  Serial2.println("Note: Enter 'd' to display menu options");
  delay(1000);
  Serial2.println("'a': automation   'f': forward   'b': reverse");
  Serial2.println("'l': turn left   'r': turn right   's': stop   'e': exit menu");
  Serial2.println("'i': input destination   'm': input multiple destinations");
  delay(50);
  Serial2.println("'e': exit menu 'd': display menu options");
  delay(50);

  while (!Quit) {                   // As long as Quit isn't true, this switch/case menu will run infinitely
    DCMotorZero();                  // For the car, you need the stop function in place while it awaits commands
    if (Serial2.available() > 0) {
      b = Serial2.read();
      switch (b) {
        case 'a':     // Letter a
          Serial2.println("Commencing automation procedures");
          automation(latitA, lonA, latitB, lonB);                     // The function that activates the car's automation functions
          if (latitC == 0.00 && lonC == 0.00) {
            Serial2.println("There are no more destinations to move to! Returning to main menu...");
            delay(3000);
            break;
          }
          GPSTelemetry();
          automation(latitA, lonA, latitC, lonC);
          if (latitD == 0.00 && lonD == 0.00) {
            Serial2.println("There are no more destinations to move to! Returning to main menu...");
            delay(3000);
            break;
          }
          GPSTelemetry();
          automation(latitA, lonA, latitD, lonD);
          Serial2.println("You have used up all available destinations! Returning to main menu...");
          break;
        case 'f':     // Letter f
          Serial2.println("The car moves forward!");
          goStraightShortDistance( 1200 );  // Make car go forward for 1200 milliseconds (manual control)
          break;
        case 'b':     // Letter b
          Serial2.println("The car moves in reverse!");
          goReverseShortDistance( 1200 );   // Make care go reverse for 1200 milliseconds (manual control)
          break;
        case 'l':     // Letter l
          Serial2.println("The car turns left!");
          leftTurnTimed( 1300 );              // Turn left for 1200 milliseconds (manual control)
          break;
        case 'r':     // Letter r
          Serial2.println("The car turns right!");
          rightTurnTimed( 1200 );             // Turn right for 1200 milliseconds (manual control)
          break;
        case 's':     // Letter s
          Serial2.println("The car will stop for 10 seconds.");
          stopCarTimed(10000);              // Stop car for 10 seconds
          delay(1000);                      // This is helpful for inputting multiple commands at once
          break;
        case 'i':     // Letter i
          Serial2.println("Input a single destination coordinate");
          inputDestination();              // Go to function to input new destination
          break;                           // This only works for ONE destination
        case 'm':     // Letter m
          Serial2.println("Input multiple destination coordinates (up to THREE)");
          multipleDestinations();               // Go to function to input THREE destinations
          break;                                // This only works for MULTIPLE destination
        case 'e':     // Letter e
          Serial2.println("Exiting the menu.");   // Quit the menu
          Quit = true;                            // This wont do anything because there's nothing after
          break;                                  // MenuFunction() in loop. It'll just go back to MenuFunction()
        case 'd':     // Letter d
          Serial2.println("Displaying Main Menu options");
          Serial2.println("Main Menu");
          Serial2.println("Enter the following lowercase characters for menu options");
          Serial2.println("Note: Enter 'd' to display menu options");
          delay(1000);
          Serial2.println("'a': automation   'f': forward   'b': reverse");
          Serial2.println("'l': turn left   'r': turn right   's': stop   'e': exit menu");
          Serial2.println("'i': input destination   'm': input multiple destinations");
          delay(50);
          Serial2.println("'e': exit menu 'd': display menu options");
          delay(50);
          break;
      }
      delay(50);
    }
  }
}
