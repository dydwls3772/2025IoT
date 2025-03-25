#4주차 사물인터넷

통신프로토콜

컴퓨터나 원거리 통신 장비 사이에서 메시지를 주고 받는 양식과 규칙의 체계

I2C를 이용한 아두이LCD제어
Hello World 출력코드
```c
#include <Wire.h>				// I2C 통신을 위한 기본 라이브러리
#include <LiquidCrystal_I2C.h>	// I2C LCD 라이브러리


LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.init();					// I2C LCD 초기화
  lcd.backlight();				// 백라이트 켜기
  lcd.print("LCD init");
  delay (2000);
  lcd.clear();
}

void loop()
{
  lcd.setCursor(0,0);
  lcd.print("Hello, World!");
            
  for (int position = 0; position < 16; position++){
    lcd.scrollDisplayLeft();
    delay (150);
  }
}
```
미세먼지센 데이터를 LCD에 출력하는 코드
```c
#include <Wire.h>				// I2C 통신을 위한 기본 라이브러리
 #include <LiquidCrystal_I2C.h>	// I2C LCD 라이브러리
 
 
 LiquidCrystal_I2C lcd(0x27, 16, 2);
 
 int Vo = A0;
 int V_led = 7;
 
 float Vo_value = 0;
 float Voltage = 0;
 float dustDensity = 0;
 
 void setup()
 {
   pinMode(V_led, OUTPUT);
   pinMode(Vo, INPUT);
   lcd.init();					// I2C LCD 초기화
   lcd.backlight();				// 백라이트 켜기
   lcd.print("LCD init");
   delay (2000);
   lcd.clear();
 }
 
 void loop()
 {
   digitalWrite(V_led, LOW);
   delayMicroseconds(280);
   Vo_value = analogRead(Vo);
   delayMicroseconds(40);
   digitalWrite(V_led, HIGH);
   delayMicroseconds(9680);
 
   Voltage = Vo_value*5.0 / 1023.0;
   dustDensity = (Voltage - 0.5)/0.005;
   lcd.setCursor(0,0);
 
   lcd.print(dustDensity);
   lcd.print("um");       
   delay (150);
   lcd.clear();
 
 }
```
초음파센서 데이터를 LCD에 출력하는 코드
```c
#include <Wire.h>				//I2C 통신을 위한 기본 라이브러리
#include <LiquidCrystal_I2C.h>  //I2C LCD 라이브러리
#define TRIG 7 //TRIC 핀
#define ECHO 6 //ECHO 핀

#include <Wire.h>				//I2C 통신을 위한 기본 라이브러리
#include <LiquidCrystal_I2C.h>  //I2C LCD 라이브러리
#define TRIG 13 //TRIC 핀
#define ECHO 12 //ECHO 핀

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  Serial.begin(9600); // 괄호 안은 속도를 의미
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  lcd.init();			// I2C LCD 초기화
  lcd.backlight();	    // 백라이트 켜기
  lcd.print("LCD init");
  delay (2000);
  lcd.clear();
}

void loop()
{
  long duration,distance;
  
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  
  distance = duration / 58.2;
  
  

  lcd.setCursor(16,0);
  lcd.print(distance);
  delay (1500);
  lcd.clear();
  
  for (int position = 0; position < 16; position++) {
    lcd.scrollDisplayLeft();
    delay(150);
    }
  }
```
