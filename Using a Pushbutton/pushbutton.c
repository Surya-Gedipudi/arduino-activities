/*
Name: Surya Gedipudi
Project: Pushbutton
*/

// Global Constants and Variables
const int btnPin = 2; // Pin used to read button state
int btnState = 0;     // Button is initially not pressed
                      //  if btnState = 0 (not pressed)
                      //  if btnState = 1 (pressed)

void setup()
{
    pinMode(btnPin, INPUT);

    // Serial connection allows PC and Arduino to communicate
    // PC and Arduino must be set to the same communication speed
    // Serial monitor will display the button state as "HIGH" (1)
    Serial.begin(9600); // Start the serial monitor at 9600 bps
}

void loop()
{
    // Read btnPin value (0 or 1 will be returned)
    btnState = digitalRead(btnPin);

    // Display state of button (HIGH or LOW) on serial monitor
    if (btnState == HIGH)
    {
        delay(10); // Debounce button for 10ms
        Serial.println("HIGH");
    }
    else
    {
        Serial.println("LOW");
    }

    // Delay 1ms before next button state is read
    delay(1);
}