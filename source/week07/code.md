# 7주차 실습코드

1초마다 if 블록 실행하는 코드
~~~ c
void setup() {
  Serial.begin(115200);
  Serial.println();
}

void loop() {
  static unsigned long loopCnt = 0;
  static unsigned long nextMil = millis() + 1000;

  loopCnt++; // loopCnt = loopCnt + 1;

  if (millis() > nextMil){
    nextMil = millis() + 1000;
    Serial.println(loopCnt);
    loopCnt = 0;
  }
}
~~~
Simple Timer를 이용한 타이머코드
~~~ c
#include <SimpleTimer.h>
SimpleTimer timerCnt;

unsigned long loopCnt;

void timerCntFunc() {
  Serial.println(loopCnt);
  loopCnt = 0;
}

void setup() {
  Serial.begin(115200);
  Serial.println();

  timerCnt.setInterval(1000,timerCntFunc);  // milli-sec,func
}

void loop() {
  timerCnt.run();
  loopCnt++; // loopCnt = loopCnt + 1;
}
~~~
함수를 호출하는 코드
~~~ c
int a1 = 2;
int a2 = 3;
int a3;

void setup() {
  Serial.begin(115200);
  Serial.println();

  sum(a1,a2,a3);
  Serial.println(a3);
}

void loop() {
}

void sum(int a, int b, int& c){
  c = a + b;
}
~~~
Dev-C++를 이용한 클래스코드
~~~ c
#include <LedToggle.h>

LedToggle led(LED_BUILTIN);


void setup(){
}

void loop() {
  led.toggle();
}
~~~
