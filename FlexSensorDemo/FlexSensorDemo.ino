/* How to use a flex sensor/resistro - Arduino Tutorial
   Fade an LED with a flex sensor
   More info: http://www.ardumotive.com/how-to-use-a-flex-sensor-en.html
   Dev: Michalis Vasilakis // Date: 9/7/2015 // www.ardumotive.com  */


//Constants:
const int ledPin0 = 2;   //pin 2 has PWM funtion
const int ledPin1 = 3;
const int ledPin2 = 4;
const int ledPin3 = 5;
const int flexPinA2 = A2; // yellow
const int flexPinA3 = A3; // blue
const int flexPinA4 = A4; // green
const int flexPinA5 = A5; // black

//Variables:
int valueYellowA2; //save analog value
int valueBlueA3;
int valueGreenA3;
int valueBlackA5;

void setup() {

  pinMode(ledPin0, OUTPUT);  //Set pin 4 as 'output'
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  Serial.begin(9600);       //Begin serial communication

}

void loop() {

  valueYellowA2 = analogRead(flexPinA2) - 350;         //Read and save analog value from potentiometer
  valueBlueA3 = analogRead(flexPinA3) - 376;
  valueGreenA3 = analogRead(flexPinA4) - 360;
  valueBlackA5 = analogRead(flexPinA5) - 361;
  // Serial.println(valueYellowA2); //Print value
  // Serial.println(valueBlueA3);
  // Serial.println(valueGreenA3);
   Serial.println(valueBlackA5);
  valueYellowA2 = map(valueYellowA2, 400, 600, 0, 255);//Map value 0-1023 to 0-255 (PWM)
  valueBlueA3 = map(valueBlueA3, 400, 600, 0, 255);
  valueGreenA3 = map(valueGreenA3, 400, 600, 0, 255);
  valueBlackA5 = map(valueBlackA5, 400, 600, 0, 255);
  //  analogWrite(ledPin0, valueYellowA2);          //Send PWM value to led
  //  analogWrite(ledPin1, valueBlueA3);
  //  analogWrite(ledPin2, valueGreenA3);
  //  analogWrite(ledPin3, valueBlackA5);
  delay(500);                          //Small delay
}


