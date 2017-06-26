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
const int NUM_EACH_CORNER = 90;

//Left-upper-corner (green)
int left_upper_corner1[NUM_EACH_LINE] = {59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30};
int left_upper_corner2[NUM_EACH_LINE] = {60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89};
int left_upper_corner3[NUM_EACH_LINE] = {179, 178, 177, 176, 175, 174, 173, 172, 171, 170, 169, 168, 167, 166, 165, 164, 163, 162, 161, 160, 159, 158, 157, 156, 155, 154, 153, 152, 151, 150};
int left_upper_all[NUM_EACH_CORNER] = {59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30,
                                       60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
                                       179, 178, 177, 176, 175, 174, 173, 172, 171, 170, 169, 168, 167, 166, 165, 164, 163, 162, 161, 160, 159, 158, 157, 156, 155, 154, 153, 152, 151, 150
                                      };

//Left-lower-corner (yellow)
int left_lower_corner1[NUM_EACH_LINE] = {180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209};
int left_lower_corner2[NUM_EACH_LINE] = {299, 298, 297, 296, 295, 294, 293, 292, 291, 290, 289, 288, 287, 286, 285, 284, 283, 282, 281, 280, 279, 278, 277, 276, 275, 274, 273, 272, 271, 270};
int left_lower_corner3[NUM_EACH_LINE] = {300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329};
int left_lower_all[NUM_EACH_CORNER] = {180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209,
                                       299, 298, 297, 296, 295, 294, 293, 292, 291, 290, 289, 288, 287, 286, 285, 284, 283, 282, 281, 280, 279, 278, 277, 276, 275, 274, 273, 272, 271, 270,
                                       300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329
                                      };

//Right-upper-corner (black)
int right_upper_corner1[NUM_EACH_LINE] = {29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
int right_upper_corner2[NUM_EACH_LINE] = {90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119};
int right_upper_corner3[NUM_EACH_LINE] = {149, 148, 147, 146, 145, 144, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 122, 121, 120};
int right_upper_all[NUM_EACH_CORNER] = {29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0,
                                        90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
                                        149, 148, 147, 146, 145, 144, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 122, 121, 120
                                       };

//Right-lower-corner (blue)
int right_lower_corner1[NUM_EACH_LINE] = {210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239};
int right_lower_corner2[NUM_EACH_LINE] = {269, 268, 267, 266, 265, 264, 263, 262, 261, 260, 259, 258, 257, 256, 255, 254, 253, 252, 251, 250, 249, 248, 247, 246, 245, 244, 243, 242, 241, 240};
int right_lower_corner3[NUM_EACH_LINE] = {330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359};
int right_lower_all[NUM_EACH_CORNER] = {210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
                                        269, 268, 267, 266, 265, 264, 263, 262, 261, 260, 259, 258, 257, 256, 255, 254, 253, 252, 251, 250, 249, 248, 247, 246, 245, 244, 243, 242, 241, 240,
                                        330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359
                                       };


//Variables:
int valueYellowA2; //save analog value
int valueBlueA3;
int valueGreenA4;
int valueBlackA5;

int initYellow;
int initBlue;
int initGreen;
int initBlack;

char text[10];

//Set the mode
/*
   1 = test mode
   2 = all LEDs in each Corner
   3 = theaterChaseRainbow
   4 = theaterChaseRainbowEachCorner
   5 = rainbow
   6 = rainbowCycle
   7 = fill corner
   8 = Write Text
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

  //Write on wall method:
  strcpy(text, "Hallo!");

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
    case 3:
      // Code
      theaterChaseRainbow(50);
      break;
    case 4:
      // Code
      theaterChaseRainbowEachCorner(flexPinA2, initYellow, left_lower_all, 0);
      theaterChaseRainbowEachCorner(flexPinA3, initBlue, right_lower_all, 0);
      theaterChaseRainbowEachCorner(flexPinA4, initGreen, left_upper_all, 0);
      theaterChaseRainbowEachCorner(flexPinA5, initBlack, right_upper_all, 0);
      strip.show();
      break;
    case 5:
      // Code
      rainbow(20);
      break;
    case 6:
      // Code
      rainbowCycle(20);
      break;
    case 7:
      // Code
      fillCorner(flexPinA2, initYellow, left_lower_all, 50);
      fillCorner(flexPinA3, initBlue, right_lower_all, 50);
      fillCorner(flexPinA4, initGreen, left_upper_all, 50);
      fillCorner(flexPinA5, initBlack, right_upper_all, 50);
      strip.show();
      break;
    case 8:
      // Code
      writeOnWall(500);
      strip.show();
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

//MODE 1: single-LED in each corner
void touchedNEO(int value, int init, int startLED) {
  if (value > (init + THRESHOLD)) {
    strip.setPixelColor(startLED, strip.Color(0, 255, 0));
  } else {
    strip.setPixelColor(startLED, strip.Color(0, 0, 255));
  }
}

//MODE 2: multi-LED in each corner
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

//MODE 8: Write Text on Wall
void writeOnWall(int wait) {
  for (int i = 0; i < 10; i++) {
    if (text[i] == 'H') {
      //Left of the 'H'
      strip.setPixelColor(59, strip.Color(0, 255, 0));
      strip.setPixelColor(60, strip.Color(0, 255, 0));
      strip.setPixelColor(179, strip.Color(0, 255, 0));
      strip.setPixelColor(180, strip.Color(0, 255, 0));
      strip.setPixelColor(299, strip.Color(0, 255, 0));
      strip.setPixelColor(300, strip.Color(0, 255, 0));
      //Right of the 'H'
      strip.setPixelColor(30, strip.Color(0, 255, 0));
      strip.setPixelColor(89, strip.Color(0, 255, 0));
      strip.setPixelColor(150, strip.Color(0, 255, 0));
      strip.setPixelColor(209, strip.Color(0, 255, 0));
      strip.setPixelColor(270, strip.Color(0, 255, 0));
      strip.setPixelColor(329, strip.Color(0, 255, 0));
      for (int i = 0; i < NUM_EACH_LINE; i++) {
        strip.setPixelColor(left_upper_corner3[i], strip.Color(0, 255, 0));
      }
      strip.show();
      delay(wait);
      clareAllLeft();
      delay(wait);
    }
    if (text[i] == 'a') {
      //Left of the 'a'
      strip.setPixelColor(59, strip.Color(0, 255, 0));
      strip.setPixelColor(60, strip.Color(0, 255, 0));
      strip.setPixelColor(179, strip.Color(0, 255, 0));
      strip.setPixelColor(180, strip.Color(0, 255, 0));
      strip.setPixelColor(299, strip.Color(0, 255, 0));
      strip.setPixelColor(300, strip.Color(0, 255, 0));
      //Right of the 'a'
      strip.setPixelColor(30, strip.Color(0, 255, 0));
      strip.setPixelColor(89, strip.Color(0, 255, 0));
      strip.setPixelColor(150, strip.Color(0, 255, 0));
      strip.setPixelColor(209, strip.Color(0, 255, 0));
      strip.setPixelColor(270, strip.Color(0, 255, 0));
      strip.setPixelColor(329, strip.Color(0, 255, 0));
      for (int i = 0; i < NUM_EACH_LINE; i++) {
        strip.setPixelColor(left_upper_corner3[i], strip.Color(0, 255, 0));
      }
      for (int i = 0; i < NUM_EACH_LINE; i++) {
        strip.setPixelColor(left_upper_corner1[i], strip.Color(0, 255, 0));
      }
      strip.show();
      delay(wait);
      clareAllLeft();
      delay(wait);
    }
    if (text[i] == 'l') {
      //Left of the 'l'
      strip.setPixelColor(59, strip.Color(0, 255, 0));
      strip.setPixelColor(60, strip.Color(0, 255, 0));
      strip.setPixelColor(179, strip.Color(0, 255, 0));
      strip.setPixelColor(180, strip.Color(0, 255, 0));
      strip.setPixelColor(299, strip.Color(0, 255, 0));
      strip.setPixelColor(300, strip.Color(0, 255, 0));
      for (int i = 0; i < NUM_EACH_LINE; i++) {
        strip.setPixelColor(left_lower_corner3[i], strip.Color(0, 255, 0));
      }
      strip.show();
      delay(wait);
      clareAllLeft();
      delay(wait);
    }
    if (text[i] == 'o') {
      //Left of the 'o'
      strip.setPixelColor(59, strip.Color(0, 255, 0));
      strip.setPixelColor(60, strip.Color(0, 255, 0));
      strip.setPixelColor(179, strip.Color(0, 255, 0));
      strip.setPixelColor(180, strip.Color(0, 255, 0));
      strip.setPixelColor(299, strip.Color(0, 255, 0));
      strip.setPixelColor(300, strip.Color(0, 255, 0));
      //Right of the 'o'
      strip.setPixelColor(30, strip.Color(0, 255, 0));
      strip.setPixelColor(89, strip.Color(0, 255, 0));
      strip.setPixelColor(150, strip.Color(0, 255, 0));
      strip.setPixelColor(209, strip.Color(0, 255, 0));
      strip.setPixelColor(270, strip.Color(0, 255, 0));
      strip.setPixelColor(329, strip.Color(0, 255, 0));
      for (int i = 0; i < NUM_EACH_LINE; i++) {
        strip.setPixelColor(left_upper_corner1[i], strip.Color(0, 255, 0));
      }
      for (int i = 0; i < NUM_EACH_LINE; i++) {
        strip.setPixelColor(left_lower_corner3[i], strip.Color(0, 255, 0));
      }
      strip.show();
      delay(wait);
      clareAllLeft();
      delay(wait);
    }
    if (text[i] == '!') {
      for (int i = 0; i < NUM_EACH_CORNER; i++) {
        strip.setPixelColor(left_upper_all[i], strip.Color(0, 0, 255));
      }
      for (int i = 0; i < NUM_EACH_CORNER; i++) {
        strip.setPixelColor(left_lower_all[i], strip.Color(0, 0, 255));
      }
      strip.show();
      delay(wait);
      clareAllLeft();
      delay(wait);
    }
  }
}
//CLEAR ALL LEFT
void clareAllLeft() {
  switchOffCorner(left_upper_all);
  switchOffCorner(left_lower_all);
  strip.show();
}

//MODE 7: Fill Corner
void fillCorner(int flexPin, int init, int corner[NUM_EACH_CORNER], uint8_t wait) {
  if (analogRead(flexPin) > (init + THRESHOLD)) {
    for (int i = 0; i < NUM_EACH_CORNER; i++) {
      if (analogRead(flexPin) > (init + THRESHOLD)) {
        strip.setPixelColor(corner[i], strip.Color(0, 255, 0));
        delay(wait);
        strip.show();
      }
      else {
        switchOffCorner(corner);
      }
    }
  }
}

//MODE 6: Raibbow-Cycle
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//MODE 5: Rainbow
void rainbow(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256; j++) {
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//MODE 4: Theatre-style crawling lights with rainbow effect (each corner alone)
void theaterChaseRainbowEachCorner(int flexPin, int init, int corner[NUM_EACH_CORNER], uint8_t wait) {
  if (analogRead(flexPin) > (init + THRESHOLD)) {
    for (int j = 0; j < 256; j++) {   // cycle all 256 colors in the wheel
      for (int q = 0; q < 3; q++) {
        for (uint16_t i = 0; i < NUM_EACH_CORNER - 3; i = i + 3) { //-3 => otherwise you are leaving the corner!!!
          //Check every time, otherwise the color-wheel will not stop immediately
          if (analogRead(flexPin) > (init + THRESHOLD)) {
            strip.setPixelColor(corner[i + q], Wheel( (i + j) % 255)); //turn every third pixel on
          }
          else {
            switchOffCorner(corner);
            break;
          }
        }
        strip.show();
      }
    }
  }
}
//SWITCH OFF all LEDs of the corner
void switchOffCorner(int corner[NUM_EACH_CORNER]) {
  //for-loop through the int-array and switch off all LEDs
  for (int i = 0; i < NUM_EACH_CORNER; i++) {
    strip.setPixelColor(corner[i], strip.Color(0, 0, 0));
  }
}

//MODE 3: Theatre-style crawling lights with rainbow effect (whole wall)
void theaterChaseRainbow(uint8_t wait) {
  for (int j = 0; j < 256; j++) {   // cycle all 256 colors in the wheel
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, Wheel( (i + j) % 255)); //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

