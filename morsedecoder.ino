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
const unsigned long debounceDelay = 50;

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
int lastReading = LOW;
unsigned long lastDebouncedTime = 0;


void setup()
{
    pinMode(buttonPin, INPUT);
    Serial.begin(baudRate);
}

void loop()
{
    int reading = digitalRead(buttonPin);
    resetDebounceTimer(reading);
    if (isReadyToReadButtonState()) {
        if (isButtonStateChanged(reading)) {
            buttonState = reading;
            handleButtonStateChange(buttonState);
        }
    }
    lastReading = reading;
}

bool isButtonStateChanged(int reading)
{
    return reading != buttonState;
}

void resetDebounceTimer(int reading)
{
    if (reading != lastReading)
    {
        lastDebouncedTime = millis();
    }
}

bool isReadyToReadButtonState()
{
    return ((millis() - lastDebouncedTime) > debounceDelay);
}

void handleButtonStateChange(int state)
{
    if (state == HIGH) {
        Serial.write("pressed");
    }
}
