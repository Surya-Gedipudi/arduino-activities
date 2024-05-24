/*
Name: Surya Gedipudi
Project: Temperature Sensor
*/

// Define constants and variables
const int tempPin = A0; // Pin to access temp. sensor
char deg[] = "xC2\xB0"; // UTF-8 Code degree symbol designation

// Setup
void setup()
{
    pinMode(tempPin, INPUT);
    Serial.begin(9600);
}

// Loop
void loop()
{
    int tempSignal = analogRead(tempPin);         // read and convert sensor value to digital(0 - 1023)
    float voltage = tempSignal * (5000 / 1024.0); // convert ADC value to voltage
    float celsius = (voltage - 500) / 10;         // convert voltage to temperature (deg-C)

    int fahrenheit = ((celsius * 9) / 5 + 32); // convert deg-C to deg-F

    // print will print items but won't move to a new line
    Serial.print("Temperature: " + String(celsius) + deg + "C / "); // format output

    // println will print the item then move to a new line
    Serial.println(String(fahrenheit) + deg + "F");
    delay(1000); // wait 1 second between sensor readings
}