# 5주차 사물인터넷

## 사물인터넷 개요

2008년 가트너에서 처음 사용한 초열결 사회 말은 4차 산업혁명 시대의 특징 중 하나를 설명하는 말로 모든 사물과 데이터, 인간의 행동 등이 거미줄처럼 촘촘하게 네트워크로 연결되는 사회를 뜻한다   
IoT: 모든 사물 또는 시스템이 작게는 센서부터 크게는 도시 규모까지 모두 연결되는 기술기반   
1차 산업혁명: 증기기관에 의한 도시화   
2차 산업혁명: 전기 에너지에 의한 대량생산   
3차 산업혁명: 개인용 컴퓨터와 네트워크 등의 정보통신기술 혁신   
4차 산업혁명: 인공지능, 빅데이터, IoT에 의한 초연결 사회   

### IoT의 이해

IoT란 말은 1999년에 캐빈 애시톤이 처음 제안한 후 대중화된 용어   
좁은 의미: 유비쿼터스 환경에서 사물끼리 통신을 주고받는 것   
넓은 의미:인간, 사물, 서비스가 인간의 명시적 개입 없이 상호 협력해 센싱, 네트워킹, 정보 처리 등의 지능적 관계를 형성 하는 사물 공간 연결망   

### IoT의 요소

연결: 기기와 서비스 인프라를 묶는 역할을 하는 유·무선통신 혹은 네트워크 인프라   
정보: 정보의 생산은 곧 주변 환경과 상태의 정보를 얻어내는 센싱 기술, 정보는 생성되는 지점에 의미가 있음   
서비스: 사람에게 제공을 목적으로 정보를 묶고 가공해 제공하는 서비스   
서비스를 제공하기 위한 서비스 연동 인터페이스 기술   

### IoT의 주요 기술

센싱 기술   
물리적 센서는 표준화된 인터페이스와 정보처리 능력을 탑재한 스마트 센서로 발전   
센싱 기술의 특징   
- 프로토콜의 이종성
- 정보 보안 문제
- 자원의 제약성
- 이동성이 있다   
유·무선통신 및 네트워크 인프라 기술   
근거리 통신기술   
대표적인 근거리 통신기술은 WPAN으로, 지그비, 블루투스, NFC 등과 같은 무선통신기술이 해당   
무선 이동통신기술   
2G: 음성을 디지털로 보냄   
3G: 음성 + 데이터를 보냄   
4G: 고속 데이터 전속   
5G: 초고속, 초저지연, 대용량연결   
유선통신기술   
이더넷 기반의 표준 IP 통신 방식: 기존의 폐쇄적이고 특정 환경에서만 동작하는 프로토콜을 대체 또는 변환해서 사용   
서비스 인터페이스 기술   
인간, 사물, 서비스를 결합하는 기능을 수행해 인간에게 제공되는 응용 서비스와 연동하는 역할을 수행   

### IoT 플랫폼

센싱: 디바이스 플랫폼   
네트워크: 데이터 플랫폼, 연결플랫폼   
서비스: 서비스 플랫폼   

### 사물인터넷 개념

센서, 일상용품이 네트워크에 연결되어 인간의 개입이 거의 없이 정보를 생성, 교환, 소비하여 정해진 기능을 하는 것   
사물인터넷 활용분야   
- 스마트홈
- 스마트시티
- 스마트 팩토리
- 헬스케어

## 사물인터넷 아두이노C++프로그래밍

### 변수

변수 선언 형식   
bool 참과 거짓을 표현하는 정수 범위: 0, 1    
int 카운트용 정수 범위: -32.768 ~ 32.767   
unsigned long 가장 큰 정수, 시간표시용 범위: 0 ~ 약42억   
float 소수점 있는 숫자 범위: 유효숫자 6자리   
char 문자 한 개 범위: -128 ~ 127   
Strung 문자열을 보관하는 클래스 범위: 연속된 문자 묶음    

변수명   
영문자, 숫자, 그리고_(underscore)를 섞어 변수명을 만든다. 숫자로 시작하면 안되며, 중간에 빈칸이 있으면 안된다, 영문자는 대소문자를 구분한다.   
낙타등 표기법: 첫 단어는 소문자, 이후의 단어는 첫 글자만 대문자로 작성한다.   

변수의 적용 범위   
전역변수: 메모리가 끝까지 유지되며 가용 메모리가 줄어든다.   
지역변수: 선언된 함수 또는 블록 안에서만 통용 메모리 활용면에서 유리   

변수의 속성 지정   
const: 중간에 바뀌지 않는값   
static: 함수안에서 계속사용되는값 선언된 변수의 초기화는 최초 한번만 수행된다   

숫자형변수   
bool:  참(true, HIGH, 1)과 거짓(false, LOW, 0)의 상태만 보관   
int: 가장 간단히 처리할 수 있는 정수형   
unsigned long: 밀리초 단위의 시간을 보관하는 변수   
float: 메모리에 숫자의 부호, 유효숫자, 지수를 분리하여 표현   
byte: 1바이트로 부호없이 정수 표현 메모리 절약에 사용 Unsigned char과 같은 의미   
uint8_t: typedef라는 지시어를 이용해 정의한 데이터형 Byte나 unsigned char와 같다    

산술연산자   
연산자 우선순위   
1: a++, a--   
2: --a, ++a   
3: *, /, %  
4: +, -   

### 배열
배열을 초기화하고 한꺼번에 다루기   
배열을 모두 0으로 초기화하는 방법   
float temp[3] = {};   

### 문자형 변수

char   
char형 변수는 1바이트의 부호가 있는 정수로 문자 표시 용도로 쓰인다.   
\n – 코드(10진수): 10 코드(16진수): 0a 설명: 새 줄(new line)   
\r – 코드(10진수): 13 코드(16진수): 0d 설명: 새 줄(carriage return)   
\t – 코드(10진수): 9 코드(16진수): 09 설명: 수평 탭   
char배열 만드는 방법    
문자열은 char 변수의 배열(array) 또는 char 포인터(pointer)를 사용하여 문자열을 표시한다.   
'/0’는 널(null)이라고 부르고 정수로는 0이다.   
char 배열을 다루는 함수   
strcpy: 첫 인수에 두 번째 인수의 값을 복사함   
strcat: 첫 인수에 두 번째 인수의 값을 덧붙임    
strlen: 인수의 문자 개수를 돌려줌   
strcmp: 비교 – 1: 첫 인수가 클 때 0: 두 인수가 같을 때 –1: 첫 인수가 작을 때   
char 포인터   
포인터는 메모리 상의 특정 주소다. char*와 같이 *를 붙이면 변수형의 포인터 변수라는 의미다.   
String   
초보자가 C++로 문자열을 다루기는 힘들다. 아두이노에서는 쉽게 문자열을 다루기 위해 String 클래스를 만들었다.   
String 오브젝트는 몇 개든 +로 연결할 수 있으며. 연결할 대상 중 적어도 하나는 String 오브젝트 속성을 가져야 한다.   

### 조건문

if문   
조건식이 참일 때에만 {} 안의 프로그램을 수행한다.   
메소드 Serial.available()은 버퍼에 문자가 도착해 있으면 참이 된다.   
if else문   
조건식의 참 거짓을 구분하여 {} 안의 프로그램을 수행한다.   
if else if문   
여러 개의 조건식을 차례로 따져 {} 안의 프로그램을 수행한다.   
switch문   
하나의 변숫값을 비교하여 여러 값으로 나누어 수행할 때 사용한다.   
삼항 연산자(? : )   
여러 줄의 조건식을 한 줄로 표현할 때 사용한다.   

### 시리얼 통신

아두이노 보드와 PC 간의 시리얼 통신   
보드와 PC 모두 USB 모듈이 있으므로 USB 케이블로 연결한다.   
USB 모듈의 도움을 받지만 두 기기는 시리얼로 통신한다.   
write: 메모리상의 내용을 1바이트로 출력   
