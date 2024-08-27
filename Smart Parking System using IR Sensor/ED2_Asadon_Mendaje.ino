int SensorPin = 2;
int OutputPin = 13;
int SensorPin2 = 3;
int OutputPin2 = 12;
int SensorPin3 = 4;
int OutputPin3 = 11;
int buzz = 7;
int SensorValue;
int SensorValue2;
int SensorValue3;


void setup() {
  pinMode(OutputPin, OUTPUT);
  pinMode(SensorPin, INPUT);
  pinMode(OutputPin2, OUTPUT);
  
  pinMode(SensorPin2, INPUT);
  pinMode(OutputPin3, OUTPUT);
  pinMode(SensorPin3, INPUT);
  pinMode(buzz, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  SensorValue = digitalRead(SensorPin);
  SensorValue2 = digitalRead(SensorPin2);
  SensorValue3 = digitalRead(SensorPin3);
   if (SensorValue==1)  { 
    digitalWrite(OutputPin, HIGH);
    digitalWrite(OutputPin2, LOW);
    digitalWrite(OutputPin3, LOW);
       




 


digitalWrite(buzz, LOW);
  
}
  else if (SensorValue2==1) {
   
 digitalWrite(OutputPin, LOW);
    digitalWrite(OutputPin2, HIGH);
    digitalWrite(OutputPin3, LOW);
        digitalWrite(buzz, LOW);
  }
    else if (SensorValue==3)  { 
  digitalWrite(OutputPin, LOW);
    digitalWrite(OutputPin2, LOW);
    digitalWrite(OutputPin3, HIGH);
        digitalWrite(buzz, LOW);


  }
    else if ((SensorValue==1) && (SensorValue2==1) && (SensorValue3==1)) { 
    digitalWrite(OutputPin, HIGH);
    digitalWrite(OutputPin2, HIGH);
    digitalWrite(OutputPin3, HIGH);
    digitalWrite(buzz, HIGH);
  }
  else{
    digitalWrite(OutputPin, LOW);
    digitalWrite(OutputPin2, LOW);
    digitalWrite(OutputPin3, LOW);
        digitalWrite(buzz, LOW);


  }
}

