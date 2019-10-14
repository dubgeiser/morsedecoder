/*
International Morse Code
https://en.wikipedia.org/wiki/Morse_code

    1. The length of a dot is 1 unit
    2. A dash is 3 units
    3. The space between parts of the same letter is 1 unit
    4. The space between letters is 3 units
    5. The space between words is 7 units
*/

const int buttonPin = 2;
const int baudRate = 9600;

String letters[] = {
    ".-",
    "-...",
    "-.-.",
    "-..",
    ".",
    "..-.",
    "--.",
    "....",
    "..",
    ".---",
    "-.-",
    ".-..",
    "--",
    "-.",
    "---",
    ".--.",
    "--.-",
    ".-.",
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    "-..-",
    "-.--",
    "--.."
};
String digits[] = {
    "-----",
    ".----",
    "..---",
    "...--",
    "....-",
    ".....",
    "-....",
    "--...",
    "---..",
    "----."
};
int buttonState;
int lastButtonState = LOW;


void setup()
{
    pinMode(buttonPin, INPUT);
    Serial.begin(baudRate);
}


void loop()
{
    buttonState = digitalRead(buttonPin);
    if (isButtonStateChanged()) {
        lastButtonState = buttonState;
        if (buttonState == HIGH) {
            Serial.write("pressed");
        }
    }
}


bool isButtonStateChanged()
{
    return lastButtonState != buttonState;
}
