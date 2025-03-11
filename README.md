# 2025

```c
#define TRIG 13
#define ECHO 12

int led_R = 6;
int led_G = 9;


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(led_R, OUTPUT);
  pinMode(led_G, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = duration / 58.2;
  
  Serial.print (distance);
  Serial.println(" Cm");
  delay(1000);
  // put your main code here, to run repeatedly:

  if(distance >=100)
  {
    digitalWrite(led_R, HIGH);
    digitalWrite(led_G, LOW);
  }
  else
  {
    digitalWrite(led_R, LOW);
    digitalWrite(led_G, HIGH);
  }
  delay(1000);
  //digitalWrite(led_R, HIGH);
  //delay(1000);
  //digitalWrite(led_R, LOW);
  //delay(1000);
  //digitalWrite(led_G, HIGH);
  //delay(1000);
  //digitalWrite(led_G, LOW);
  //delay(1000);
}

```
