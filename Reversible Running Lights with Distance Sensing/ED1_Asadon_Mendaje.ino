int LED1 = 7;
int LED2 = 8;
int LED3 = 9;
int LED4 = 10;
int LED5 = 11;
int speed = 50;
int speed2 = 100;
int speed3 = 200;
int trig_pin = 13;
int echo_pin = 12;


float duration;
float distance;
int time;
int value = 0;


void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  Serial.begin(9600);


}


void myFunction(){
  digitalWrite(LED1, HIGH);
  delay(time);                      
  digitalWrite(LED1, LOW);   
  delay(time);
  digitalWrite(LED2, HIGH);
  delay(time);                      
  digitalWrite(LED2, LOW);   
  delay(time);    
  digitalWrite(LED3, HIGH);
  delay(time);                      
  digitalWrite(LED3, LOW);   
  delay(time);       
  digitalWrite(LED4, HIGH);
  delay(time);                      
  digitalWrite(LED4, LOW);   
  delay(time);   
  digitalWrite(LED5, HIGH);
  delay(time);                       
  digitalWrite(LED5, LOW);
  delay(time);                      
  digitalWrite(LED4, HIGH);
  delay(time);                      
  digitalWrite(LED4, LOW);   
  delay(time); 
  digitalWrite(LED3, HIGH);
  delay(time);                      
  digitalWrite(LED3, LOW);   
  delay(time);
  digitalWrite(LED2, HIGH);
  delay(time);                      
  digitalWrite(LED2, LOW);   
  delay(time);  
  digitalWrite(LED1, HIGH);
  delay(time);                      
  digitalWrite(LED1, LOW);   
  delay(time);}


void loop() {
 
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);


  duration = pulseIn(echo_pin, HIGH);
  distance = (duration/2)/29;
  Serial.print("Distance: ");
  Serial.println(distance);
  
   if (distance <= 5){
  time = speed;
  myFunction();
            
   }
    else if (distance >= 6 && distance <= 10) {
  time = speed2;
  myFunction();   }
  
else{
    time = speed3;
  myFunction();}
  
    }
