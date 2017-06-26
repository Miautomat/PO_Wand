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

//Threshold
const int THRESHOLD = 30;
const int NUM_EACH_LINE = 30;

//Left-upper-corner (green)
int left_upper_corner1[NUM_EACH_LINE] = {59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30};
int left_upper_corner2[NUM_EACH_LINE] = {60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89};
int left_upper_corner3[NUM_EACH_LINE] = {179, 178, 177, 176, 175, 174, 173, 172, 171, 170, 169, 168, 167, 166, 165, 164, 163, 162, 161, 160, 159, 158, 157, 156, 155, 154, 153, 152, 151, 150};

//Left-lower-corner (yellow)
int left_lower_corner1[NUM_EACH_LINE] = {180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209};
int left_lower_corner2[NUM_EACH_LINE] = {299, 298, 297, 296, 295, 294, 293, 292, 291, 290, 289, 288, 287, 286, 285, 284, 283, 282, 281, 280, 279, 278, 277, 276, 275, 274, 273, 272, 271, 270};
int left_lower_corner3[NUM_EACH_LINE] = {300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329};

//Right-upper-corner (black)
int right_upper_corner1[NUM_EACH_LINE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
int right_upper_corner2[NUM_EACH_LINE] = {90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119};
int right_upper_corner3[NUM_EACH_LINE] = {149, 148, 147, 146, 145, 144, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 122, 121, 120};

//Right-lower-corner (black)
int right_lower_corner1[NUM_EACH_LINE] = {210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239};
int right_lower_corner2[NUM_EACH_LINE] = {269, 268, 267, 266, 265, 264, 263, 262, 261, 260, 259, 258, 257, 256, 255, 254, 253, 252, 251, 250, 249, 248, 247, 246, 245, 244, 243, 242, 241, 240};
int right_lower_corner3[NUM_EACH_LINE] = {330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359};



//Variables:
int valueYellowA2; //save analog value
int valueBlueA3;
int valueGreenA4;
int valueBlackA5;

int initYellow;
int initBlue;
int initGreen;
int initBlack;

//Set the mode
/*
   1 = test mode
   2 = all LEDs in each Corner
   3 = ...
*/
int mode = 2;

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

  switch ( mode ) {
    case 1:
      // Code
      touchedNEO(analogRead(flexPinA2), initYellow, 300);
      touchedNEO(analogRead(flexPinA3), initBlue, 359);
      touchedNEO(analogRead(flexPinA4), initGreen, 59);
      touchedNEO(analogRead(flexPinA5), initBlack, 0);
      strip.show();
      break;
    case 2:
      // Code
      touchedNEOmulti(analogRead(flexPinA2), initYellow, left_lower_corner1, left_lower_corner2, left_lower_corner3);
      touchedNEOmulti(analogRead(flexPinA3), initBlue, right_lower_corner1, right_lower_corner2, right_lower_corner3);
      touchedNEOmulti(analogRead(flexPinA4), initGreen, left_upper_corner1, left_upper_corner2, left_upper_corner3);
      touchedNEOmulti(analogRead(flexPinA5), initBlack, right_upper_corner1, right_upper_corner2, right_upper_corner3);
      break;
    default:
      // Code
      break;
  }

  //delay(500);                          //Small delay
}

void touched(int value, int init, int ledPin) {
  if (value > (init + THRESHOLD)) {
    analogWrite(ledPin, 100);
  } else {
    analogWrite(ledPin, 0);
  }
}

//single-LED in each corner
void touchedNEO(int value, int init, int startLED) {
  if (value > (init + THRESHOLD)) {
    strip.setPixelColor(startLED, strip.Color(0, 255, 0));
  } else {
    strip.setPixelColor(startLED, strip.Color(0, 0, 255));
  }
}

//multi-LED in each corner
void touchedNEOmulti(int value, int init, int topLine[NUM_EACH_LINE], int middleLine[NUM_EACH_LINE], int downLine[NUM_EACH_LINE]) {
  if (value > (init + THRESHOLD)) {
    //for-loop through the int-array
    for (int i = 0; i < NUM_EACH_LINE; i++) {
      strip.setPixelColor(topLine[i], strip.Color(255, 0, 0));
    }
    for (int i = 0; i < NUM_EACH_LINE; i++) {
      strip.setPixelColor(middleLine[i], strip.Color(255, 0, 0));
    }
    for (int i = 0; i < NUM_EACH_LINE; i++) {
      strip.setPixelColor(downLine[i], strip.Color(255, 0, 0));
    }
  } else {
    //for-loop through the int-array and switch off all LEDs
    for (int i = 0; i < NUM_EACH_LINE; i++) {
      strip.setPixelColor(topLine[i], strip.Color(0, 0, 0));
    }
    for (int i = 0; i < NUM_EACH_LINE; i++) {
      strip.setPixelColor(middleLine[i], strip.Color(0, 0, 0));
    }
    for (int i = 0; i < NUM_EACH_LINE; i++) {
      strip.setPixelColor(downLine[i], strip.Color(0, 0, 0));
    }

    //for left-lower corner
    if (topLine[0] == 180) {
      strip.setPixelColor(downLine[0], strip.Color(0, 0, 255));
    }
    //for richt-lower corner
    else if (topLine[0] == 210) {
      //set indicator-LED
      strip.setPixelColor(downLine[29], strip.Color(0, 0, 255));
    }
    //for left and right upper corner
    else {
      //set indicator-LED
      strip.setPixelColor(topLine[0], strip.Color(0, 0, 255));
    }
    //show
    strip.show();
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

