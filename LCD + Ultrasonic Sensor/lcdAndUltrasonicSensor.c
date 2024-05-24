/*
Name: Surya Gedipudi
Project: LCD + Ultrasonic Sensor
*/

#include <Wire.h>
#include <hd44780.h>                       // main hd44780 header
#include <hd44780ioClass/hd44780_I2Cexp.h> // i2C expander i/o class header

hd44780_I2Cexp lcd; // declare lcd object: auto locate & config expander chip

// Define pins for rangefinder
// define and assign the trig pin
int trigPin = 10;
// define assign echo pin
int echoPin = 9;
// define a int variable for distance
int distance;
// define a long variable for duration
long duration;

// LCD geometry
const int LCD_COLS = 16;
const int LCD_ROWS = 2;

// Setup LCD & pinmodes
void setup()
{
    checkLCDstatus();
    // set the pinmode for the trigPin
    pinMode(trigPin, OUTPUT);
    // set the pinmode for the echoPin
    pinMode(echoPin, INPUT);
    // start the serial monitor
    Serial.begin(9600);
}

void loop()
{
    range();                                           // call range function
    lcd.setCursor(0, 0);                               // set cursor at position 0, row 0
    lcd.clear();                                       // clear the lcd
    lcd.print("UltraSonic");                           // print "UltraSonic"
    lcd.setCursor(0, 1);                               // set cursor at position 0, row 1
    lcd.print("Distance: " + String(distance) + "cm"); // print distance & units to lcd
    Serial.println(String(distance) + "cm");           // print distance & units to serial
    delay(200);                                        // set a delay of 200
}

// Code the range() function which wil calculate the distance
void range()
{
    digitalWrite(trigPin, LOW);        // set the trigPin LOW to clear it
    delayMicroseconds(2);              // 2 microsecond delay
    digitalWrite(trigPin, HIGH);       // set trigPin HIGH
    delayMicroseconds(10);             // 10 microsecond delay
    digitalWrite(trigPin, LOW);        // set trigPin LOW
    duration = pulseIn(echoPin, HIGH); // set echoPin HIGH
    distance = duration * 0.034 / 2;   // distance calculation
}

void checkLCDstatus()
{
    // check status of LCD initilization
    int status;

    // Notes:
    // 1: a status value (returned from begin()) can be used to troubleshoot
    //    a failed initialization. actual status codes are defined in <hd44780.h>
    //    See the values RV_XXXX
    // 2: lcd.begin() will automatically turn on the backlight
    // 3: lcd.noBacklight()() will turn the backlight off

    status = lcd.begin(LCD_COLS, LCD_ROWS);

    if (status)
    {
        status = -status; // convert negative status value to positive number
        / begin() failed so blink error code using the onboard LED if possible
                hd44780::fatalError(status); // does not return
    }
}