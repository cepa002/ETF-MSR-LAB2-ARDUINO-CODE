// the setup routine runs once when you press reset:

int ledGreen = 7;  
int ledRed = 8;
int ledWhite = 9;
int buttonPin = 2;
int ledBlue = 3;

void setup() {
  // initialize serial communication at 9600 bits per second:
  pinMode(ledGreen,OUTPUT);
  pinMode(ledRed,OUTPUT);
  pinMode(ledWhite,OUTPUT);
  pinMode(ledBlue,OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  
  int sensorValue = analogRead(A0);
  int sensorValue1 = analogRead(A1);
  int buttonVal = digitalRead(buttonPin);
  
  if (buttonVal == HIGH) {
    digitalWrite(ledBlue, HIGH);
  } else {
    digitalWrite(ledBlue, LOW);
  }

  
  float volt = 5 * (float)sensorValue/1023 * 1000;
  float brightness = 255 * (float)sensorValue/1023;
  analogWrite(ledWhite, brightness);
  
  if(volt >= 4500){
    digitalWrite(ledRed, LOW);
  	digitalWrite(ledGreen, HIGH);
  }
  else if(volt <= 500){
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);
  }
  else{
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, LOW);
  }
  
  volt/=1000;
  // print out the value you read:
  //Serial.println(volt);
  //Serial.println(sensorValue1);
  Serial.println(brightness);
  //delay(10);  // delay in between reads for stability
}