

#include <Encoder.h>

const int Key_S1 = 6; //K1
const int Key_S2 = 7; //K2

const int PWM_Pin = 5; //PWM
const int DIR_Pin = 4; //DIR

const int E_A = 3; //A
const int E_B = 2; //B
Encoder myEnc(E_A, E_B);

const int analogInPin = A0; //DIR

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
long oldPosition  = -999;
long newPosition=0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);     //LED_BUILTIN=Pin 13
  pinMode(Key_S1, INPUT);     //K1
  pinMode(Key_S2, INPUT);     //K2
  pinMode(PWM_Pin, OUTPUT);     
  pinMode(DIR_Pin, OUTPUT);   
  pinMode(E_A, INPUT);     
  pinMode(E_B, INPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  //Bilink();
  //testKEY();
  Motortest();
  Encoder_1();

  CurrentSensor();

    Serial.print("Encoder = ");
    Serial.print(newPosition);
    Serial.print("\t Motor Courrent sensor = ");
    Serial.println(sensorValue);
}

void Bilink(){
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000); 
}

void testKEY(){
if(digitalRead(Key_S1)==LOW) 
    digitalWrite(LED_BUILTIN, LOW);  // turn the LED on 
  else
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED off 
}
void Motortest(){
if(digitalRead(Key_S1)==LOW) {
    digitalWrite(DIR_Pin, HIGH);
    digitalWrite(PWM_Pin, HIGH);}
  else if(digitalRead(Key_S2)==LOW){
    digitalWrite(DIR_Pin, HIGH);
    analogWrite(PWM_Pin, 30);}
}
void Encoder_1(){
     newPosition = myEnc.read();
    if (newPosition != oldPosition) {
    oldPosition = newPosition;

  }
}

void CurrentSensor(){
sensorValue = analogRead(analogInPin);
outputValue = map(sensorValue, 0, 1023, 0, 255);

}
