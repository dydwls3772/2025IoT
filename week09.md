# 9주차 사물인터넷

## 라즈베리파이 os 설치   

1. 라즈베리파이 공식 홈페이지에 라즈베리파이 이미저 설치
2. 설치 후 라이즈베리파이 이미저 실행
3. 라즈베리파이 디바이스/운영체제 선택 후 SD카드에 설
4. SD카드를 라즈베리파이 삽입 후 모니터와 연결

## 라즈베리파이 OS 환경설정
*인터넷 연결*   
1. 기본화면 우측 상단 블루투스 옆 인터넷 연결상태 아이콘 클릭
2. Advanced Options 클릭후 Edit Connections 클릭
3. 이더넷 선택 후 옵션 ipv4설정 클릭
4. method(수동) 으로 변경 후 주소와 DNS 서버주소 작성 후 저장

*키보드 설정*
1. 좌측상단 라즈베리파이 아이콘 클릭
2. 기본 설정(Preferences) 클릭
3. 키보드 마우스 설정(Mouse and Keyboard Settings) 클릭후 키보드 클릭
4. keyboard layout 클릭 후 환경에 맞게 설정

*한글화*
1. 좌측상단 라즈베리파이 아이콘 클릭
2. 기본 설정(Preferences) 클릭
3. 라즈베리파이 환경설정(Raspberry pi configuration) 클릭
4. 현지화(Localisation)클릭 후 Locale, Timezone 설정
5. 터미널 클릭후
6. 아래 코드를 입력
```
sudo apt_get install fonts-unfonts-core -y
sudo apt_get install ibus ibus-hangul -y
sudo reboot
```
