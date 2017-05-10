/*
Current Pin Layout:

HC-SR04(Ultrasonic Sensor)
ECHO: Digital I/O Pin 13
TRIG:  Digital I/O Pin 12
VCC: 5V Pin
GND: any GND pin

Buzzer: Digital I/O Pin 7

*/

#define trigPin 13
#define echoPin 12
#define led 11
#define led2 10
#define buzzer 7

void setup() 
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buzzer, OUTPUT);

  /*allows buzzer to ring for 1 second
  to confirm sound is working*/
  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
  
}

void loop()
{
   digitalWrite(buzzer,HIGH);

  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);

  /*calculates distance of object based on 
    time taken to pulse */
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;



  /*defines out of range distances */
  if (distance >= 200 || distance <= 0)
  {
    Serial.println("Out of range");
  }
  else 
  {
    Serial.print(distance);
    Serial.println(" cm");
  }


  /* generates delays based on distance*/
  digitalWrite(buzzer,HIGH);
  delay((distance*100));
  digitalWrite(buzzer, LOW);
    
  /*end of loop delay so that sounds do not clash*/
  delay(100);
  
}

