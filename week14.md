# 사물인터넷 14주

## IEEE표준에 따른 비교
IEEE 802.11의 주파수 대역은 2.4GHz & 5GHz    
MAC방식은 b, a, g, n 모두 CSMA방식을 사용     
전송방식은 주파수를 분활해서 통신하는지 아니면 스펙트럼을 나눠서 통신을 하는지에 따라 전송방식의 차이가 있다      
도달거리는 802.11b, 802.11g, 802.11n은 100m이고 802.11a는 50m이다.    
IEEE는 전기, 전자공학, 컴퓨터 공학, 정보 기술 등 다양한 공학 분야에서 세계 최대의 전문가 단체이다.   

## Wi-Fi 구성
IEEE 802.11 Working Group에서 표준화 작업    
AP (Access Point)와 station (STA)으로 구성    
AP: 유무선 공유기    
STA: 노트북, 스마트폰 등    

## Wi-Fi Service Set
BSS(Basic Service Set) : 가장 기본적인 Service Set으로 일반 가정에서 사용된다. AP가 없으면 ad hoc모드 AP가 있으면 infrastructure 모드     
ESS(Extended Service Set) : 학교나 거리가있는 장소에 사용되는 것으로 두 개 이상의 BSS들이 모여서 구성된다.    

## MAC 방식
PCF(Point coordination function) :　Option, 중앙집중식 Polling 방식 사용    
DCF(Distributed coordination function) : 일반적인 방식 CSMA/CA 사용. Station에서 사용    

## CSMA-CA(Carrier sense Multiple Access with Collision Avoidance)
CS (Carrier Sense) : 네트워크가 현재 사용 중인지 알아냄    
MA (Multiple Access) : 네트워크가 비어있으면 누구든 사용 가능     
CA (Collision Avoidance) : 충돌 회피, Wi-Fi에서 사용하는 방식    

## 충돌(컬리젼, Collision)
두 개 이상의 노드가 같은 시간대에 같은 노드에게 패킷을 전송    
RTS, CTS를 사용하면, 충돌이 발생할 확률이 줄어듦 - CA방식    

## Hidden Terminal Problem (숨겨진 노드 문제)
중간 터미널(A)는 양쪽 터미널(B,C)와 통신이 가능        
양쪽 터미널(B,C)는 서로의 통신을 감지하지 못함      

## 일반적인 CSMA-CA 동작 방식
경합 방식 : 채널을 사용하고자 하는 기기들 끼리 경쟁     
1. 다른 기기가 데이터를 송신중인지 감지     
2. 송신중이면 대기(백오프)한다.    
3. 송신 시작까지의 시간은 랜덤 한 시간이 할당된다.    
4. 기다린 후, 다시 반송파 감지를 해서 다른 반송파가 있는지 확인    
5. 데이터 전송을 시작한다.    

## RTS-CTS-DATA-ACK 방식 (일반적 CSMA-CA)
송신 측에서 RTS 전송 후 충돌이 발생하는지 확인 후, 수신 측에서 CTS를 정확하게 다시 받으면 DATA를 보낸 후 ACK를 받는다.    

## CSMA-CD (Collision Detection)
이더넷에 쓰이는 채널 접근 방식으로 송신 중 충돌이 감지되면, 전송을 중지하고 랜덤한 시간동안 기다리고 (백오프), 다시 전송 시도

## CSMA-CA의 CSMA-CD와 비교한 장단점
장점: 저 가격으로 구현     
단점: 데이터 전송이 많이 지연될 수 있음    
(전송 빈도가 높아지면, 충돌 방지 신호의 전송 속도가 느려짐)    

## ZigBee 스택
스택 :　프로토콜, 소프트웨어 관한 집합체라 볼 수 있음    
지그비 스택 : 지그비에서 정의한 프로토콜 들의 구현    

## IEEE 802.15.4 PHY 계층 특징
무선으로 직접 데이터를 주고 받는 계층    
3개의 밴드에 27개의 채널 사용    
PHY(868/915MHz) Frequoncy Band(868-870MHz) Channel Numbering 0    
PHY(868/915MHz) Frequoncy Band(902-928MHz) Channel Numbering 1 to 10    
PHY(2.4GHz) Frequoncy Band(2.4-2.4835GHz) Channel Numbering 11 to 26    
       
2.4GHz 대역에서 무선 랜과 겹치는 채널있음     
Channel 25, 26번은 독자적으로 겹치지 않음     
Channel 15, 20번도 무선 랜의 채널 선택이 권고안대로 되어 있다면 겹치지 않음     
무선 랜이 사용하지 않는 채널 구간은 사용 가능     

## DSSS (Direct Sequence Spread Spectrum)
양쪽 모두가 알고 있는 슈도 랜덤(pseudo random) 값인 +1 이나 -1을 데이터에 곱해서 보낸다.

## MAC 계층 특징
Network Coordinator (NC) : 네트워크 코디네이터      
Full Function Device(FFD) : 전기능기기    
Reduced Function Device(RFD) : 축소기능기기     

## MAC의 선택 사양
비콘 없는 (Non-Beacon) 통신 : Non-slotted CSMA-CA 통신, 수신 패킷 성공을 위해 확인 응답          
비콘 (Beacon) 사용 통신 :  Slotted CSMA-CA 통신, 슈퍼 프레임 사용        

## 지그비의 CSMA-CA
RTS, CTS 를 사용하지 않음

## 슈퍼 프레임 (Super Frame) 구조
비콘 (Beacon), CAP(Contention Access Period),CFP(Contention Free Period)으로 구성      
시간을 슬롯단위로 0부터 15까지 나누어 최대 16개의 슬롯으로 구성.     
      
Beacon (비콘) : 비콘에 따라 시간 동기화를 하여 슬롯 단위 송수신 가능– GTS가 어느 기기에 할당되었는지 알려줌     
    
비활성화 구간 : 지그비 기기의 전력 사용을 적게 하여 기기 수명을 늘기위해 사용    
 
## MAC 주소
PAN (Personal Area Network) ID + 주소      
PAN ID : 네트워크 주소, 코디네이터가 할당한 ID      
Address : 2 Byte 또는 8 Byte        
2 Byte : 코디네이터가 할당해준 주소      
8 Byte : 처음 제작될 때 제작사가 할당해준 주소    

## MAC 주소 표시 방법
같은 네트워크 내: 목적지 주소(2) + 근원지 주소(2) → 4byte     
다른 네트워크 간 :      
목적지 PAN ID(2) + 목적지 주소(2)      
근원지 PAN ID(2) + 근원지 주소(2) → 8 byte      
다른 네트워크 간에서 패런츠가 부여한 주소를 사용하지 않을 때:     
목적지 PAN ID(2) + 목적지 주소(8)       
근원지 PAN ID(2) + 근원지 주소(8) → 20 byte     

## 분산 주소 할당 기법 (Distributed Address AssignmentMechanism)
ZigBee 라우터는 모두 자신의 자식 노드에게 주소 할당을 할 수 있음→ 분산 방식   
분산 주소 할당 기법의 장점: 네트워크 상의 트래픽을 줄일 수 있음   
ZigBee의 경우 대규모 네트워크를 형성해야 해서 분산 주소 할당을 사용한다.    
중앙 집중 할당 기법은 하나의 노드가 모든 네트워크의 기기의 주소를 할당 하는 기법으로 제어 메시지 (제어 트래픽)이 많이 필요하다.    
### 분산 할당 식 - 깊이에 따른 주소 할당 크기    
Cskip(d) = (1+Cm-Rm-Cm*Rm(Lm-d-1) )/ (1-Rm)    
### 분산 할당의 예    
Cm = 3, Rm = 3, Lm = 3    
