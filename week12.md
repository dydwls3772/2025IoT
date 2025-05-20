# 12주차 사물인터넷

## 라즈베리파이 InfluxDB 설치 코드
출처: https://github.com/sonnonet/2024_inhatc    
InfluxDB download key using wget
```
wget -q https://repos.influxdata.com/influxdata-archive_compat.key
echo '393e8779c89ac8d958f81f942f9ad7fb82a25e133faddaf92e15b16e6ac9ce4c influxdata-archive_compat.key' | sha256sum -c && cat influxdata-archive_compat.key | gpg --dearmor | sudo tee /etc/apt/trusted.gpg.d/influxdata-archive_compat.gpg > /dev/null
echo 'deb [signed-by=/etc/apt/trusted.gpg.d/influxdata-archive_compat.gpg] https://repos.influxdata.com/debian stable main' | sudo tee /etc/apt/sources.list.d/influxdata.list
```
Packages are up to date && install Influxdb
```
 sudo apt-get update && sudo apt-get install influxdb -y
```
InfluxDB as a background service on startup
```
sudo service influxdb start
```
InfluxDB is status (service)
```
sudo service influxdb status
```
### Python InfluxDB lib 설치
```
pip install influxdb
```
### Grafana Installation
1. Install the prerequisite packages
```
sudo apt-get install -y apt-transport-https software-properties-common wget
```
2. Import the GPG key:
```
sudo mkdir -p /etc/apt/keyrings/
wget -q -O - https://apt.grafana.com/gpg.key | gpg --dearmor | sudo tee /etc/apt/keyrings/grafana.gpg > /dev/null
```
3. To add a repository for stable releases, run the following command:
```
echo "deb [signed-by=/etc/apt/keyrings/grafana.gpg] https://apt.grafana.com stable main" | sudo tee -a /etc/apt/sources.list.d/grafana.list
```
4. Run the following command to update the list of available packages:
```
sudo apt-get update && sudo apt-get install grafana -y
```
5. Run the following command to server start
```
sudo systemctl start grafana-server
```
### influxdb import with python
```
pip install influxdb
```
hint: See PEP 668 for the detailed specification.
```
  sudo rm /usr/lib/python3.11/EXTERNALLY-MANAGED
```
## influxDB Database 생성
```
$ Influx
$ create database dust
$ show databases
$ exit
```
## 미세먼지 센서 코드
```python
impor time
import requests, json
from influxdb import InfluxDBClient as influxdb
import serial

seri = serial.Serial('/dev/ttyACM0', baudrate = 9600, timeout = None)

while(True):
    time.sleep(1)
    if seri.in_waiting !=0:
    content = seri.readline()
    a = float(content.decode())
    data = [{
        'measurement' : 'dust',
        'tags':{
            'InhaUni' : '2222',
        },
        'fields':{
              'dust' : a,
        }
    }]
    client = None
    try:
        client = influxdb('localhost',8086,'root','root','dust')
    except Exception as e:
      print ("Exception" + str(e))
    if client is not None:
        try:
            client.write_points(data)
        except Exception as e:
            print ("Exception write " + str(e))
        finally:
            client.close()
    print(a)
    print("running influxdb OK")
```
## Grafana 접속
1. 크롬미니 -> localhost:3000
2. username : admin , password : admin
3. Connections -> Data sources
4. add data source -> InfluxDB
5. InfluxDB 연결 설정 -> http://localhost:8086
6. InfluxDB 연결 설정 -> Database : dust, User : root, password: root
    
Dashboards 설정
1. Dashboards -> New -> New dashboard
2. Add visualization
3. 본인이 설정한 data source 지정
4. select measurement -> dust
5. tag -> inhaUni = 2222
6. field(value) ->dust

## 텔레그램 봇에 미세먼지센서 값 보내기
### 텔레그램 봇 설정
```
git clone https://github.com/python-telegram-bot/python-telegram-bot
$ cd python-telegram-bot/examples
$ vim timerbot.py
```
timerbot.py에 아래 코드 작성   
```python
application.add_handler(CommandHandler("dust", dustToInfluxDB))

import serial

seri = serial.Serial('/dev/ttyACM0', baudrate = 9600, timeont = None)

async def alarm(context: ContextTypes.DEFAULT_TYPE) -> None:
    if seri.in_waiting !=0:
      content = seri.readline()
      a = float(content.decode())
    job = context.job
    await context.bot.send_message(job.chat_id, text=f"Dust Sensor Value! {a}")


async def set_timer(update: Update, context: ContextTypes.DEFAULT_TYPE) -> None:
    """Add a job to the queue."""
    chat_id = update.effective_message.chat_id
    try:
        # args[0] should contain the time for the timer in seconds
        due = float(context.args[0])
        if due < 0:
            await update.effective_message.reply_text("Sorry we can not go back to future!")
            return

        job_removed = remove_job_if_exists(str(chat_id), context)
        context.job_queue.run_once(dustToInfluxDB, due, chat_id=chat_id, name=str(chat_id), data=due)
```
