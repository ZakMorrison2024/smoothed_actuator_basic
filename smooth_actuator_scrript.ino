// https://github.com/XRobots/ServoSmoothing/blob/main/code/sequencer/sequencer.ino

int input; // input switch
float inputsmoothed; // input smoothed variable
float inputprevious; // update input

int pin = 12; // set input pin

void setup() {
    Serial.begin(115200); // Serial

    pinMode(pin, INPUT_PULLUP); // Set up pin
}

void loop() {

input = digitalRead(pin); // Read pin
input = input * 100; // multply input by 100

// smoothing input

inputsmoothed = (input * 0.05) + (inputprevious * 0.95); // smooth input value by 0.5:0.95 ratio
inputprevious = inputsmoothed; // prevuous value == new value

// end of smoothing

Serial.print(input); // display input value
Serial.print(" , "); // sep
Serial.println(inputsmoothed); // display new value

delay(10); // delay by 10 miliseconds

}
