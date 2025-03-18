#3주차 사물인터넷
InfluxDB의 개념및 설치방법을 배우고 InfluxDB를 이용한 미세먼지세선&&아두이 연동실습

아두이노코드
```c
int Vo = A0;
int V_led = 12;

float Vo_value=0;
float Voltage = 0;
float dustDensity = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(V_led, OUTPUT);
  pinMode(Vo, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(V_led, LOW);
  delayMicroseconds(200);
  Vo_value = analogRead(Vo);
  delayMicroseconds(40);
  digitalWrite(V_led, HIGH);
  delayMicroseconds(9680);

  Voltage = Vo_value*5.0 / 1023.0;
  dustDensity = (Voltage - 0.5)/0.005;

  Serial.print("dust=" );
  Serial.println(dustDensity);

  delay(1000);
}
```
파이썬을 이용한 코드
```python
import serial
from influxdb_client import InfluxDBClient
import time

serial_port = 'COM14'
baud_rate = 9600
timeout = 2

influxdb_url = "http://localhost:8086"
influxdb_token = "0HUZEkZq3sK59uTesGasuXBt_0VqcrBR4pSO6VcQksEYFxpJ7qv922_5pMOS_uYat32rqxK9PO0EWO8xufMYqA=="
influxdb_org = "test"
influxdb_bucket = "dust"

client = InfluxDBClient(url=influxdb_url, token=influxdb_token, org=influxdb_org, bucket=influxdb_bucket)
write_api = client.write_api()

try:
    ser = serial.Serial(serial_port, baud_rate, timeout = timeout)
    print(f"Connected to {serial_port} at {baud_rate} baud")
except:
    print("Failed to connect to serial port")
    exit()
try:
    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').strip()

            if "=" in line:
                key, value = line.split("=")
            try:
                value = float(value)
                data=f"sensor_data,device=arduino {key}-{value}"
                write_api.write(bucket=influxdb_bucket, record=data)
                print(f"Data written to influxDB: {key}={value}")
            except ValueError:
                print("lnvalid data format")
        time.sleep(1)

except KeyboardInterrupt:
        print("프로그램이 종료되었습니다.")

finally:
        ser.close()
