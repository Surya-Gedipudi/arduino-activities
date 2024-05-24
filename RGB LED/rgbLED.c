/*
Name: Surya Gedipudi
Project: LED RGB
*/

// RGBLED  r, g, & b pins must be PWM (~)
// Red pin
// Green pin
// Blue pin

// Buttons can use any digital pin
// Red button
// Green button
// Blue button

void setup()
{
    // Set pin modes for buttons

    // Set pin modes for LED pins

    // Start the serial monitor
}

void loop()
{
    // If no buttons are pressed, turn the LED off
    if ()
    {
        // Debounce button
        // LEDS off
    }

    // While red Button is pressed turn red light on
    while ()
    {
        // Set red color
    }

    // While green Button is pressed turn green light on
    while ()
    {
        // Set green color
    }

    // While blue Button is pressed turn blue light on
    while ()
    {
        // Set blue color
    }
}

// Helper function to set colors
void setColor(int red, int green, int blue)
{
    delay(10);             // Debounce button
    analogWrite(r, red);   // Set R value (0 - 255)
    analogWrite(g, green); // Set G value (0 - 255)
    analogWrite(b, blue);  // Set B value (0 - 255)
}
