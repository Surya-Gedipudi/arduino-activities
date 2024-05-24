/*
  Name: Surya Gedipudi
  Project: Ultrasonic Sensor (Range Finder)
  Objective: Record distance using the ultrasonic range
             finder and display them via serial monitor
*/

// Defines pins numbers

// Defines variables
const int trigPin = 3;
const int echoPin = 2;
long signalTime = 10;
int distance = 0;

void setup()
{
    // Sets the trigPin as an Output
    pinMode(trigPin, OUTPUT);
    // Sets the echoPin as an Input
    pinMode(echoPin, INPUT);
    // Starts the serial communication
    Serial.begin(9600);
}

void loop()
{
    range();
}

void range()
{
    // Set the trigPin LOW to clear it
    digitalWrite(trigPin, LOW);
    // 2 micro-sec delay
    delayMicroseconds(2);
    // Set trigPin HIGH to send signal out
    digitalWrite(trigPin, HIGH);

    // 10 micro-sec delay
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Set echoPin high to record signal time and assign it to your time variable.
    signalTime = pulseIn(echoPin, HIGH);

    // Distance calculation
    distance = (0.034 * signalTime) / 2;

    Serial.println("Distance: " + String(distance) + " cm"); // print distance to serial monitor
    // Serial.println(String(distance)); //print distance to Excel
    delay(100); // 100 ms wait time between readings
}