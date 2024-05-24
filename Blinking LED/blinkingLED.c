/*
  Name:
  Project: Blinking LED
*/

// Define constants and global variables
const int LEDPin = 12; // Make sure this is the same pin that
                       //  you connected the LED to

// Setup code runs once to initialize pins, serial monitor, etc.
void setup()
{
    // put your setup code here, to run once:
    pinMode(LEDPin, OUTPUT); // Setting the LEDPin to be an output
}

// Loop code runs repeatedly
void loop()
{
    digitalWrite(LEDPin, HIGH); // Turn the LED on
    delay(1000);                // Wait 1 sec
    digitalWrite(LEDPin, LOW);  // Turn the LED off
    delay(1000);                // Wait 1 sec
}