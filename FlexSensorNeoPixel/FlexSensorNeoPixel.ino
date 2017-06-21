#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(360, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

//Constants:
const int ledPin2 = 2;   //pin 2 has PWM funtion
const int ledPin3 = 3;
const int ledPin4 = 4;
const int ledPin5 = 5;
const int flexPinA2 = A2; // yellow
const int flexPinA3 = A3; // blue
const int flexPinA4 = A4; // green
const int flexPinA5 = A5; // black

//Variables:
int valueYellowA2; //save analog value
int valueBlueA3;
int valueGreenA4;
int valueBlackA5;

int initYellow;
int initBlue;
int initGreen;
int initBlack;

void setup() {

  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  //Test LEDs
  pinMode(ledPin2, OUTPUT);  //Set pin 4 as 'output'
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);

  //Init values of each FlexSensor
  initYellow = analogRead(flexPinA2);
  initBlue = analogRead(flexPinA3);
  initGreen = analogRead(flexPinA4);
  initBlack = analogRead(flexPinA5);

  Serial.begin(9600);       //Begin serial communication

}

void loop() {
  touchedNEO(analogRead(flexPinA2), initYellow, 300);
  touchedNEO(analogRead(flexPinA3), initBlue, 359);
  touchedNEO(analogRead(flexPinA4), initGreen, 59);
  touchedNEO(analogRead(flexPinA5), initBlack, 0);
  strip.show();
  //delay(500);                          //Small delay
}

void touched(int value, int init, int ledPin) {
  if (value > (init + 20)) {
    analogWrite(ledPin, 100);
  } else {
    analogWrite(ledPin, 0);
  }
}

void touchedNEO(int value, int init, int startLED) {
  if (value > (init + 20)) {
    strip.setPixelColor(startLED, strip.Color(255, 0, 0));
  } else {
    strip.setPixelColor(startLED, strip.Color(0, 0, 255));
  }
}

//Hauptprogramm
void feelTheTouch() {

}

//Test with 4 white LEDs on the breadboard
void flexLEDTest() {
  valueYellowA2 = analogRead(flexPinA2);        //Read and save analog value from potentiometer
  valueBlueA3 = analogRead(flexPinA3);
  valueGreenA4 = analogRead(flexPinA4);
  valueBlackA5 = analogRead(flexPinA5);

  touched(valueYellowA2, initYellow, ledPin2);
  touched(valueBlueA3, initBlue, ledPin3);
  touched(valueGreenA4, initGreen, ledPin4);
  touched(valueBlackA5, initBlack, ledPin5);

  //Reichenfolge der LEDs am Breadboard!!!
  Serial.println(valueGreenA4);
  Serial.println(valueYellowA2); //Print value
  Serial.println(valueBlackA5);
  Serial.println(valueBlueA3);

  Serial.println();
}

