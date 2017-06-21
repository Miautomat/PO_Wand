/* How to use a flex sensor/resistro - Arduino Tutorial
   Fade an LED with a flex sensor
   More info: http://www.ardumotive.com/how-to-use-a-flex-sensor-en.html
   Dev: Michalis Vasilakis // Date: 9/7/2015 // www.ardumotive.com  */


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

  pinMode(ledPin2, OUTPUT);  //Set pin 4 as 'output'
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);

  initYellow = analogRead(flexPinA2);
  initBlue = analogRead(flexPinA3);
  initGreen = analogRead(flexPinA4);
  initBlack = analogRead(flexPinA5);

  Serial.begin(9600);       //Begin serial communication

}

void loop() {

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

  //delay(500);                          //Small delay
}

boolean touched(int value, int init, int ledPin) {
  if (value > (init + 20)) {
    analogWrite(ledPin, 100);
  } else {
    analogWrite(ledPin, 0);
  }
}


