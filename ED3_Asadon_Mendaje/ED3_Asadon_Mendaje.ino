  #include <Servo.h>;
  Servo Servo;
  int ldrPin = A4;
  int val;
  int sensorValue;
  int sensorPin = 7;
  int led = 13;
  int servoPin = 9;
  const int rain = A3;
  const int ldr_pin = 2;
  const int led_pin = 11;
  int led1 = 4;
  int led3 = 12;
  int motionPin = 10;
  int pinStateCurrent   = LOW;
  int pinStatePrevious  = LOW;
  const int buzzer = A1; 



  void setup() {
    pinMode(sensorPin, INPUT);
    pinMode(ldr_pin,INPUT);
    pinMode(led_pin,OUTPUT);
    pinMode(led, OUTPUT);
    pinMode(servoPin, OUTPUT);
    Servo.attach(servoPin);
    Servo.write(0);
    pinMode(rain, INPUT);
    pinMode(led1, OUTPUT);
    pinMode(motionPin, INPUT);
    pinMode(led3, OUTPUT);
    pinMode(buzzer, OUTPUT);


  }

  void loop() {
    int value = analogRead(rain);//read value
    if (value < 300) {//check condition
      digitalWrite(led1, HIGH);
      Serial.println("It is raining.");
      analogWrite(buzzer, 255);
      Serial.print(" ");
    } else {
      digitalWrite(led1, LOW);
      analogWrite(buzzer, 0);

    }


    sensorValue = digitalRead(sensorPin);
    if (sensorValue == 1){
      digitalWrite(led, LOW);
      Servo.write(0);
    }
    if (sensorValue == 0) {
      digitalWrite(led, HIGH);
      Servo.write(90);
    }
    
    pinStatePrevious = pinStateCurrent; // store old state
    pinStateCurrent = digitalRead(motionPin);   // read new state


    if (pinStatePrevious == HIGH && pinStateCurrent == LOW) {   // pin state change: HIGH -> LOW
      Serial.println("Motion stopped!");
      delay(3000);
      digitalWrite(led3, LOW);
      // TODO: turn off alarm, light or deactivate a device ... here
    }
    
    if (pinStatePrevious == LOW && pinStateCurrent == HIGH) {   // pin state change: LOW -> HIGH
      Serial.println("Motion detected!");
      digitalWrite(led3, HIGH);
  
      // TODO: turn on alarm, light or activate a device ... here
    }

    // put your main code here, to run repeatedly:
    if( digitalRead( ldr_pin ) == 1){
      analogWrite(led_pin, 255);
        }
    else{
        analogWrite(led_pin, 0);
    }
    delay(100);

  }