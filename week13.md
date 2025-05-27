# 13주차 사물인터넷

## 시그윈과 지그비를 이용한 온습도센서 실습

1. 시그윈에 실습할 디렉토리 생성
2. github에 https://github.com/sonnonet/inhatc에 들어가 소스코드 다운
3. 다운받은 파일을 압축해제한 후 TestLowOneHopSht_sc 복사
4.  c드라이브에 cygwin -> home -> 생성한 디렉토리 -> 붙여넣기
5.  시그윈에서 cd TestLowOneHopSHt_sc/ 를 친다
6.  vim을 이용하여 TestAppC.nc, Test.h, TestC.nc 파일 작성
TestAppC.nc
```c
includes Test;
configuration TestAppC
{
}
implementation
{
  components TestC, MainC;
  components LedsC, new TimerMilliC();

  components ActiveMessageC as AMC;
  components new AMSenderC(AM_TEST_DATA_MSG) as AMSC;

  TestC.Boot -> MainC;
  TestC.Leds -> LedsC;
  TestC.MilliTimer -> TimerMilliC;

  TestC.RadioControl -> AMC;
  TestC.RadioSend -> AMSC;

  components new SensirionSht11C() as Sht11hC;
  TestC.Temp -> Sht11hC.Temperature;
  TestC.Humi -> Sht11hC.Humidity;

  components new IlluAdcC() as Illu;
  TestC.Illu -> Illu;

  components BatteryC;
  TestC.Battery -> BatteryC;
}
```
Test.h
```c
#ifndef TEST_H
#define TEST_H

#include "message.h"

enum {
  TEST_PERIOD = 10240LU,
};

enum {
  DFLT_VAL = 0x11,
};

enum {
  TEST_DATA_LENGTH = TOSH_DATA_LENGTH - 6,
};

enum {
  AM_TEST_DATA_MSG = 0xA4,
};

typedef nx_struct test_data_msg {
  nx_am_addr_t srcID;
  nx_uint32_t seqNo;
  nx_uint16_t type;
  nx_uint16_t Temp;
  nx_uint16_t Humi;
  nx_uint16_t Illu;
  nx_uint16_t battery;
  //nx_uint8_t testData[TEST_DATA_LENGTH];
} test_data_msg_t;

#endif // TEST_H
```
TestC.nc
```c
module TestC
{
  uses {
    interface Boot;
    interface Leds;
    interface Timer<TMilli> as MilliTimer;

    interface SplitControl as RadioControl;
    interface AMSend as RadioSend;

    interface Read<uint16_t> as Temp;
    interface Read<uint16_t> as Humi;
    interface Read<uint16_t> as Illu;

    interface Battery;
  }
}
implementation
{
  message_t testMsgBffr;
  test_data_msg_t *testMsg;

  uint32_t seqNo;
  uint8_t step;

  task void startTimer();
  event void Boot.booted() {
    testMsg = (test_data_msg_t *)call RadioSend.getPayload(
      &testMsgBffr, sizeof(test_data_msg_t));
    testMsg->srcID = TOS_NODE_ID;

    seqNo = 0;

    post startTimer();
  }

  task void startTimer() {
    call MilliTimer.startPeriodic(TEST_PERIOD);
  }

  task void radioOn();
  event void MilliTimer.fired() {
    post radioOn();
  }

  void startDone();
  task void radioOn() {
    if (call RadioControl.start() != SUCCESS) startDone();
  }

  event void RadioControl.startDone(error_t error) {
    startDone();
  }

  task void readTask();
  void startDone() {
    step = 0;
    post readTask();
    call Leds.led0Toggle();
  }

  void sendDone();
  task void sendTask() {
    testMsg->seqNo = seqNo++;
    testMsg->type = 2; // THL type 2

    if (call RadioSend.send(AM_BROADCAST_ADDR, &testMsgBffr,
      sizeof(test_data_msg_t)) != SUCCESS) sendDone();
    call Leds.led2Toggle();
  }

  event void RadioSend.sendDone(message_t* msg, error_t error) {
    sendDone();
  }

  task void radioOff();
  void sendDone() {
    call Leds.led0Off();
    call Leds.led1Off();
    call Leds.led2Off();
    post radioOff();
  }

  void stopDone();
  task void radioOff() {
    if (call RadioControl.stop() != SUCCESS) stopDone();
  }

  event void RadioControl.stopDone(error_t error) {
    stopDone();
  }

  void stopDone() {
  }

  task void readTask() {
    switch(step) {
      case 0:
        call Temp.read(); break;
      case 1:
        call Humi.read(); break;
      case 2:
        call Illu.read(); break;
      default:
        testMsg->battery = call Battery.getVoltage();
        post sendTask();
        break;
    }
    step += 1;
  }

  event void Temp.readDone(error_t error, uint16_t val) {
    // if (error != SUCCESS) call Leds.led0On();
    testMsg->Temp = error == SUCCESS ? val : 0xFFFA;
    post readTask();
  }

  event void Humi.readDone(error_t error, uint16_t val) {
    // if (error != SUCCESS) call Leds.led1On();
    testMsg->Humi = error == SUCCESS ? val : 0xFFFB;
    post readTask();
  }

  event void Illu.readDone(error_t error, uint16_t val) {
    testMsg->Illu = error == SUCCESS ? val : 0xFFFC;
    post readTask();
  }
}
```
7.컴파일한 후 make telosb 마지막에 writng TOS image가 나오면 성공    
8.kmote usb 연결 후 make telosb install.(노드아이디)를 작성 후 실행한다.
