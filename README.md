# 2025
2주차 사물 인터넷
탕커캐드및 실제 아두이노 우노를 이용한 아두이노LED 실습

아래코드는 초음파 센서를 이용하여 거리를 잰후 100cm 이상이면 빨간LED가 켜지고 그외에는 초록색 LED가 켜지는 코드
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
