#include <Servo.h>
const int PIR_Sensor = 8;
Servo doorservo;
int ldr = A0;
int led = 12;
int tmp = A1;
int motor = 11;
int d;
int const trigPin = 7;
int const echoPin = 6;
int const buzzPin = 5;



void setup()
{
  pinMode(ldr,INPUT);
  pinMode(led,OUTPUT);
  
  pinMode(tmp,INPUT);
  pinMode(motor,OUTPUT);
  doorservo.attach(10);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(buzzPin, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(9,INPUT);
  
}

void loop()
{
  int ldrs = analogRead(ldr);
  if(ldrs <= 300)
  {
  	digitalWrite(led,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
  }
  else
  {
    digitalWrite(led,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
  }
  int reading = analogRead(tmp);
  float voltage = reading * 5.0;
  voltage /= 1024.0; 
  float temperatureC = (voltage - 0.5) * 100 ;
  if(temperatureC >= 30)
  {
    digitalWrite(motor,HIGH);
  }
  else
  {
    digitalWrite(motor,LOW);
  }
  d = digitalRead(9);
    if(d== 1){
    doorservo.write(100);
  }
  else{
    doorservo.write(0);
  }
int duration, distance;
	
	digitalWrite(trigPin, HIGH); 
	delay(1);
	digitalWrite(trigPin, LOW);
	
	duration = pulseIn(echoPin, HIGH);
	
	distance = (duration/2) / 29.1;
	
    if (distance <= 50 && distance >= 0) {
    	
    	digitalWrite(buzzPin, HIGH);
    } else {
    	
    	digitalWrite(buzzPin, LOW);
    }
   
    delay(60);
  if (digitalRead(PIR_Sensor)==HIGH)
      {digitalWrite(buzzPin, HIGH);}
  
  else  {digitalWrite(buzzPin, LOW);}
}

 
