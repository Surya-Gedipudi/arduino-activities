/*
  Name: Surya Gedipudi
  Project: Morse Code
*/
const int LEDPin = 12; // Make sure this is the same pin that
                       // you connected the LED to

const int hiDot = 500;        // Delay time for dot
const int hiDash = hiDot * 2; // Delay time for dash
const int low = 500;          // Delay for off time between dots and dashes
const int letter = low * 3;   // Delay between letters

// put your setup code here, to run once:
void setup()
{
    pinMode(LEDPin, OUTPUT); // Set the LEDPin to be an output
}

// Print "Hello World" in Morse Code
void loop()
{

    letter_H();
    letter_E();
    letter_L();
    letter_L();
    letter_O();

    delay(letter * 2); // Time delay between words

    letter_W();
    letter_O();
    letter_R();
    letter_L();
    letter_D();
}

//______________________________________________________________
void dot()
{
    // Turn LED on, Wait, Turn LED off, Wait
    digitalWrite(LEDPin, HIGH);
    delay(hiDot);
    digitalWrite(LEDPin, LOW);
    delay(low);
}

void dash()
{
    // Turn LED on, Wait, Turn LED off, Wait
    digitalWrite(LEDPin, HIGH);
    delay(hiDash);
    digitalWrite(LEDPin, LOW);
    delay(low);
}

// Calls dot function once to represent letter "E"
void letter_E()
{
    // E: .
    dot();
    delay(letter);
}

// Calls dash() once and dot() twice to represent letter "D"
void letter_D()
{
    // D: -..
    dash();
    dot();
    dot();
    delay(letter);
}

// Calls dot() 4 times to represent letter "H"
void letter_H()
{
    // H: ....
    dot();
    dot();
    dot();
    dot();
    delay(letter);
}

// Calls dot(), dash(), and dot() two more times to represent letter "L"
void letter_L()
{
    // L: .-..
    dot();
    dash();
    dot();
    dot();
    delay(letter);
}

// Calls dash() to represent letter "O"
void letter_O()
{
    dash();
    dash();
    dash();
    delay(letter);
}

// Calls dot() and dash() twice to represent letter "W"
void letter_W()
{
    dot();
    dash();
    dash();
    delay(letter);
}

// Calls dot(), dash(), and then dot() once again to represnent letter "R"
void letter_R()
{
    dot();
    dash();
    dot();
    delay(letter);
}
