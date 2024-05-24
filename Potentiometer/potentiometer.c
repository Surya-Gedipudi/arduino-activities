/*
Name: Surya Gedipudi
Project: Potentiometer
*/

// Define constants and variables
const int pot = A0; // Potentiometer is an analog sensor
const int led = 3;  // LED pin
void setup()
{
    // put your setup code here, to run once:
    pinMode(pot, INPUT);  // Setting Potentiometer as input
    pinMode(led, OUTPUT); // Setting LED as output
    Serial.begin(9600);
}

void loop()
{
    // Read pot. value
    int power = analogRead(pot);
    // The map function below is traslating the values from Potentiometer into values that can be used for LED
    int ledPower = map(power, 0, 1023, 0, 255);

    // Use pWM to set the led into the desired brightness
    analogWrite(led, ledPower);

    Serial.println(power); // printing the power on the serial screen
}
