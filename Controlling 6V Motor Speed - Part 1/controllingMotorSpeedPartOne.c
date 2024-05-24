/*
  Name: Surya Gedipudi
  Project: 6V Motor, L298N and Potentiometer (Speed Control)

  Notes
  1. Control the speed of a 6V motor using hte L298N motor controller and a potentiometer.
  2. If the speed is below a certain threshold, the motor will be turned off
     to prevent the "buzzing" that occurs from insufficient input voltage. Once the
     potentiometer is turned to a high enough value, PWM will supply sufficient
     voltage to turn the motor.
  3. Motor will only turn in  forward direction (in1 = HIGH, in2 = LOW)
*/

// Power supply voltage 7.2V
// Motor A connections
const int enA = 9;            // Uses PWM to control motor speed
const int in1 = 8;            // Used to control motor direction
const int in2 = 7;            // Used to control motor direction
const int potentiometer = A0; // Potentiometer used to control motor speed
int potValue = 0;             // Store potentiometer value
int motorSpeed = 0;           // Potentiometer value mapped to PWM value

void setup()
{
    // Set all the motor control pins to OUTPUT
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);

    // Set potentiometer to INPUT
    pinMode(potentiometer, INPUT);
    Serial.begin(9600);
}

void loop()
{
    speedControl(); // Control motor speed
    delay(1000);
}

// This function lets you control direction of motors
void speedControl()
{
    potValue = analogRead(potentiometer);                        // Read potentiometer value [0, 1023]
    motorSpeed = map(potValue, 0, 1023, 0, 255);                 // Map to [0, 255] for PWM
    Serial.println(String(potValue) + "," + String(motorSpeed)); // Debug only

    // Keep motor off until PWM voltage sufficient to turn motor shaft (prevents "buzzing" sound)
    if (motorSpeed < 60)
        turnMotorsOff();

    // Turn motor in forward direction at motorSpeed
    else
    {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        analogWrite(enA, motorSpeed);
    }
}

// Turn motors off
void turnMotorsOff()
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
}
