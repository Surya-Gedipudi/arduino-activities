/*
  Name: Surya Gedipudi
  Project: Photoresistor
*/

// Global constants
const int photoResistor = A0; // Photoresistor to analog pin A0

// Global variables
int prValue;    // Store value [0, 1023] from photoresistor
int pwmPrValue; // Map photoresistor value to PWM range [0, 255]
                // Mapping from [0, 1023] to [0, 255] is necessary
                // if you want to control PWM-based devices

// Setup pinmodes and serial monitor
void setup()
{
  pinMode(photoResistor, INPUT);
  Serial.begin(9600);
}

// Print "Hello World" in Morse Code
void loop()
{
  prValue = analogRead(photoResistor);

  // Map prValue [0, 1023] to pwmPrValue [0, 255]
  // map(value, fromLow, fromHigh, toLow, toHigh)
  pwmPrValue = map(prValue, 0, 1023, 0, 255);
  Serial.println(String(prValue) + ", " + String(pwmPrValue));

  delay(2000);
}