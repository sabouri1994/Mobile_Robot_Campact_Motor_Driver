const unsigned int TRIG_PIN=35;
const unsigned int ECHO_PIN=34;
const unsigned int BAUD_RATE=9600;



void setup() {

Serial.begin(BAUD_RATE);
 pinMode(TRIG_PIN, OUTPUT);
 pinMode(ECHO_PIN, INPUT);
}

void loop () {
   

 digitalWrite(TRIG_PIN, LOW);
 delayMicroseconds(2);
 digitalWrite(TRIG_PIN, HIGH);
 delayMicroseconds(10);
 digitalWrite(TRIG_PIN, LOW);
 delayMicroseconds(2);


const unsigned long duration= pulseIn(ECHO_PIN, HIGH);
int distance= duration/29/2;

if(duration==0){
  Serial.println("Warning: no pulse from sensor");
  } 
 else{
     Serial.print("Distance: ");
     Serial.print(distance);
     Serial.print(" cm\n");
 }
delay(100);
}
