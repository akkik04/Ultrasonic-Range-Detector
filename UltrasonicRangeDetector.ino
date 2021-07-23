  /*
   * A FEW CLARIFICATIONS FOR THIS PROJECT:
   * 
   *  - THE MAXIMUM DISTANCE OF THE HC-SR04 SENSOR IS 400 CM.
   */
   
  // importing the required library to help maximize the HC-SR04's functions.
  #include <NewPing.h>

  // importing the required library to operate the LCD.
  #include <LiquidCrystal.h>

  // declaring the LCD pins.
  LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

  // defining the pins for the sensor.
  #define trig_pin 4
  #define echo_pin 13
  #define max_distance 400

  // code to access the imported library's functions.
  NewPing sensor(trig_pin, echo_pin, max_distance);

  // creating a variable to store the value for the distance.
  float distance;

// SETUP.
void setup() {

  // initializing the LCD.
  lcd.begin(16, 2);

}

// MAIN-LOOP.
void loop() {
  
  // code to receive the distance's value from the library's built-in functions.
  distance = sensor.ping_cm();

  // if-statement for handling error with the sensor out of range.
  if (distance <= 2 || distance >= 400) {

    // code to inform the user that the measurement is failed if the condition is met.
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Failed");
    
  }

  // code to proceed with the measurement if no error is detected.
  else {

    // code to print the distance through the LCD to the user.
    lcd.setCursor(0, 0);
    lcd.print("Distance in cm:");
    lcd.setCursor(0, 1);
    lcd.print(distance);
    
  }

  // code to add a delay for the effect.
  delay(450);
}
