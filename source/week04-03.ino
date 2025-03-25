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
