/*
Name: Surya Gedipudi
Project: Button + LED

Turns LED on or off when pressing a pushbutton.
The circuit:
* LED attached from pin 11 to ground with 330 ohm resistor
* pushbutton attached to pin 2 from +5V
* 10K resistor attached to pin 2 from ground
*/

// Define global constants for pin numbers
// assign the pushbutton pin to a constant integer variable
// assign the LED pin to an integer variable
int LEDPin = 11;
const int btnPin = 2;

// Define global variables
// variable for reading the pushbutton status
int btnState = 0;

void setup()
{
    // initialize the LED pin as an output:
    pinMode(LEDPin, OUTPUT);
    // initialize the pushbutton pin as an input:
    pinMode(btnPin, INPUT);
    // Serial begin line
    Serial.begin(9600);
}

void loop()
{
    // read the state of the pushbutton value:
    btnState = digitalRead(btnPin);

    if (btnState == HIGH)
    {
        delay(10); // Debounce button for 10ms
        digitalWrite(LEDPin, HIGH);
        Serial.println("HIGH");
    }
    else
    {
        digitalWrite(LEDPin, LOW);
        Serial.println("LOW");
    }
    delay(1);
}
