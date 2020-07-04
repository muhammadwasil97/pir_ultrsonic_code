int trigPin = 5;
int echoPin = 6;
int ledPin = 13;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
 
void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // declare sensor as input
 
  Serial.begin(9600);
}
 
void loop(){
  val = digitalRead(inputPin);
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0340 / 2;
  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      if(distance == 0 || distance > 200){
        Serial.println("1");
        pirState = HIGH;
      }
      else if(distance > 0 && distance <= 200){
        Serial.println("2");
        pirState = HIGH;
        }
      // We only want to print on the output change, not state
    }
  } 
  else if(val==LOW){
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH){
        if(distance == 0 || distance > 200){
          Serial.println("0");
          pirState = LOW;
      }
            
        else if(distance > 0 && distance <= 200){
          Serial.println("2");
          pirState = LOW;
      }
  }
  }
 }
