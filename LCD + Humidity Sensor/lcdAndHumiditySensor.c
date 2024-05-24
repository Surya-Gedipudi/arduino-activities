/*
Name: Surya Gedipudi
Project: LCD + Humidity Sensor
*/

#include <Wire.h>
#include <hd44780.h>                       // main hd44780 header
#include <hd44780ioClass/hd44780_I2Cexp.h> // i2C expander i/o class header
#include <Adafruit_Sensor.h>               // DHT11
#include <DHT.h>                           // DHT11

hd44780_I2Cexp lcd; // declare lcd object: auto locate & config expander chip

// LCD geometry
const int LCD_COLS = 16;
const int LCD_ROWS = 2;

// Set DHT pin:
int DHTPIN = 2;

// set DHT type
#define DHTTYPE DHT11 // DHT 11

// Decalre dht object and initialize DHT sensor:
DHT dht = DHT(DHTPIN, DHTTYPE);

// define variables
float humidity;            // humidity
float celsius;             // Temp (C)
float fahrenheit;          // Temp (F)
float heatIndexFahrenheit; // heat index (F)
float heatIndexCelsius;    // Heat index (C)

// Setup LCD & pinmodes
void setup()
{
    checkLCDstatus();

    // begin serial communication at a baud rate of 9600
    Serial.begin(9600);

    dht.begin(); // start DHT sensor
}

void loop()
{
    measure();     // call measure()
    printSerial(); // call printSerial()
    printLCD();    // call printLCD()
}

void checkLCDstatus()
{
    // check status of LCD initialization
    int status;

    // Notes:
    // 1. a status value (returned from begin()) can be used to torubleshoot
    //    a failed initialization. actual status codes are defined in <hd44780.h>
    //    See the values RV_XXXX
    // 2: lcd.begin() will automatically turn on the backlight
    // 3: lcd.noBacklight()() will turn the backlight off

    status = lcd.begin(LCD_COLS, LCD_ROWS);

    if (status) // non zero status means it was unsuccesful
    {
        status = -status; // convert negative status value to positive number
        // begin() failed so blink error code using the onboard LED if posible
        hd44780::fatalError(status); // does not return
    }
}

// code the measure function that will measure: T, H and and calculate heat indices
void measure()
{

    delay(2000); // wait 2 seconds between readings

    // reading temperature or humidity takes about 250 milliseconds
    humidity = dht.readHumidity();

    // read temps as celsius (the default)
    celsius = dht.readTemperature();

    // read temp as fahrenheit (isFahrenheit = true)
    fahrenheit = dht.readTemperature(true);

    // check if any reads failed and exit early
    if (isnan(humidity) || isnan(celsius) || isnan(fahrenheit))
    {
        Serial.println(F("Failed to read from DHT sensor!"));
        return;
    }

    // compute heat index in fahrenheit (the default)
    heatIndexFahrenheit = dht.computeHeatIndex(fahrenheit, humidity);

    // compute heat index in celsius (isFahrenheit = false)
    heatIndexCelsius = dht.computeHeatIndex(celsius, humidity, false);
}

// print output to serial monitor
void printSerial()
{
    Serial.print(" Humidity: ");       // print humidity label
    Serial.print(humidity);            // print humidity value
    Serial.print("% Temperature: ");   // print temp label
    Serial.print(celsius);             // print temp (C) value
    Serial.print("C ");                // print celsius label
    Serial.print(fahrenheit);          // print temp (F) value
    Serial.print("F Heat index: ");    // print fahrenheit label and heat index label
    Serial.print(heatIndexCelsius);    // print heat index (C)
    Serial.print("C ");                // print celsius label
    Serial.print(heatIndexFahrenheit); // print heat index (F)
    Serial.print("F");                 // print fahrenheit label
}

void printLCD()
{
    // print the temp and the humidity on the LCD:
    lcd.setCursor(0, 0);
    lcd.print("Temp: " + String(celsius) + "\xDF" + "C");
    lcd.setCursor(0, 1);
    lcd.print("Humid " + String(humidity) + "%");
}
