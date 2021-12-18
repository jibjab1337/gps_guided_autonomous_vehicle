float stringToFloatConversion() { // The function that takes our serial monitor input for coordinates
                                  // and converts it to float so that we can use it
  String inputFloat = "";

  while (Serial2.available() == 0) {} // Serial monitor will not do anything until input is entered
  inputFloat = Serial2.readString();
  float inputCoordinate = inputFloat.toFloat(); // WARNING: THIS IS NOT SUPER ACCURATE AT 6TH DECIMAL PLACE
                                                // MEANING THAT OUR COORDINATE WILL BE OFF BY 1 FT
  return inputCoordinate;                       // What the function returns. Set the function to a variable
                                                // to save the coordinates that you want
}