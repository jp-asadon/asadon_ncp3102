#include <Servo.h>;
Servo Servo;

#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); 

#include <DHT.h>
#define pinDHT 5
#define DHTTYPE DHT11
DHT dht(pinDHT, DHTTYPE);
const int buzzer = A1;
const int flamePin = A5;
const int analogInPin = A0;
int sensorValue = 0;
int LED1 = 2; // red
int LED2 = 4;
int flame;
int smoke;
const int smoke1 = A3;
int threshold = 200;


int servoPin = 6;

float temp;
float humid;
int pinDHT11 = 9;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(flamePin, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(smoke1, INPUT);
  dht.begin();
  pinMode(buzzer, OUTPUT);
  pinMode(servoPin, OUTPUT);
  pinMode(LED2, OUTPUT);
  Servo.attach(servoPin);
  Servo.write(0);
  Serial.begin(9600);
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
}

void myFunction(){
  digitalWrite(LED2, HIGH);
  delay(300);
    digitalWrite(LED2, LOW);
  delay(300);
  digitalWrite(LED2, HIGH);
  delay(300);
    digitalWrite(LED2, LOW);
  delay(300);
  digitalWrite(LED2, HIGH);
  delay(300);
    digitalWrite(LED2, LOW);
  delay(300);
  digitalWrite(LED2, HIGH);
  delay(300);
    digitalWrite(LED2, LOW);
}
void loop() {
  
  flame = digitalRead(flamePin);
  smoke = analogRead(smoke1);

  

  Serial.println("Smoke");
  Serial.println(smoke);
    do {
    Servo.write(90);
    digitalWrite(LED2, HIGH);
    analogWrite(buzzer, 255);
    smoke = analogRead(smoke1);
  }while (smoke > 100);
      digitalWrite(LED2, LOW);

  // {
  //   digitalWrite(LED2, LOW);
  //   analogWrite(buzzer, 0);
  //   }
  

  if (flame == 0){
    Servo.write(90);
    analogWrite(buzzer, 255);
    digitalWrite(LED1, HIGH);
  flame = digitalRead(flamePin);
  } else{
    Servo.write(0);
    analogWrite(buzzer, 0);
    digitalWrite(LED1, LOW); 
}

  humid = dht.readHumidity();
  temp = dht.readTemperature();

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("°C, Humidity: ");
  Serial.print(humid);
  Serial.println("%");
  delay(2000);
  if (temp > 25){
    digitalWrite(LED1, HIGH);
    temp = dht.readTemperature();
  }else {
    digitalWrite(LED1, LOW);
  }

  sensorValue = analogRead(analogInPin);
  Serial.print("Water level sensor = ");
  Serial.print(sensorValue);
  Serial.print("\n");
  Serial.print(sensorValue);
    Serial.print("\n");

  if(sensorValue > threshold){
    analogWrite(buzzer, 255);
    myFunction();
    }
  else{
    digitalWrite(LED1, LOW);
    analogWrite(buzzer, 0);
    }
// Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) != "F7 0B FB 29") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Access Denied");
    Serial.println();
    analogWrite(buzzer, 255);
    Servo.write(0);
    // if(! mfrc522.PICC_ReadCardSerial()){
    // Servo.write(0);
    // }
  }
  else 
  {
    Serial.println(" Access Granted");
    Serial.println();
    Servo.write(90);
    analogWrite(buzzer, 0);
    delay(3000);
    //delay(3000);
  }

}