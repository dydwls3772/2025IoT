# 11주차 사물인터넷

라즈베리파이를 이용하여 텔레그램에 사진을 보내는 실습   
1. 라즈베리파이와 연결된 카메라를 작동할 파이썬 코드작성
```
$ vim test.py
```
```python

import sv2
import sys
import time

cap = cv2.videoCapture(0)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
if not cap.isOpened():
    print("camera open error")
    exit()

while True:
    ret, image=cap.read()
    if not ret:
        print("frame read error")
        break
    cv2.imshow('CAMERA', image)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

#  if cv2.waitKey(30)>0:
#      break
    time.sleep(10)
    cv2.imwrite("image.jpg", image)

cap.release()
cv2.destroyAllWindows()
```
2. 텔레그 봇 설정
```
git clone https://github.com/python-telegram-bot/python-telegram-bot
```
```
$ cd python-telegram-bot/examples
$ vim timerbot.py
```
timerbot파일 안에 token에 텔레그램 봇 생성시 받은 토큰으 넣고 아래 코드로 실행
```
$ python timerbot.py
```

3. 텔레그램 봇에 /test를 보내면 내가 원하는 메세지를 보내는 설정   
timerbot.py 파일에 아래 코드를 추가후 실
```python
application.add_handler(CommandHandler("test", test))

async def test(update: Update, context: ContextTypes.DEFAULT_TYPE) -> None:
    """Sends explanation on how to use the bot."""
    await update.message.reply_text("원하는 메세지 작성")
```

4.라즈베리파이에 연결된 카메라로 사진을 찍은 후 텔레그램 11주차 사물인터넷

라즈베리파이를 이용하여 텔레그램에 사진을 보내는 실습   
1. 라즈베리파이와 연결된 카메라를 작동할 파이썬 코드작성
```
$ vim test.py
```
```python

import sv2
import sys
import time

cap = cv2.videoCapture(0)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
if not cap.isOpened():
    print("camera open error")
    exit()

while True:
    ret, image=cap.read()
    if not ret:
        print("frame read error")
        break
    cv2.imshow('CAMERA', image)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

#  if cv2.waitKey(30)>0:
#      break
    time.sleep(10)
    cv2.imwrite("image.jpg", image)

cap.release()
cv2.destroyAllWindows()
```
2. 텔레그 봇 설정
```
git clone https://github.com/python-telegram-bot/python-telegram-bot
```
```
$ cd python-telegram-bot/examples
$ vim timerbot.py
```
timerbot파일 안에 token에 텔레그램 봇 생성시 받은 토큰으 넣고 아래 코드로 실행
```
$ python timerbot.py
```

3. 텔레그램 봇에 /test를 보내면 내가 원하는 메세지를 보내는 설정   
timerbot.py 파일에 아래 코드를 추가후 실행
```python
application.add_handler(CommandHandler("test", test))

async def test(update: Update, context: ContextTypes.DEFAULT_TYPE) -> None:
    """Sends explanation on how to use the bot."""
    await update.message.reply_text("원하는 메세지 작성")
```

4.라즈베리파이에 연결된 카메라로 사진을 찍은 후 텔레그램 봇에 전송
timerbot.py 파일에 아래 코드를 추가후 실행
```python
# Enable logging
logging.basicConfig(
    format="%(asctime)s - %(name)s - %(levelname)s - %(message)s", level=logging.INFO
)

# EDITING CODE
def takePhoto():
    cap = cv2.videoCapture(0)
    cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
    if not cap.isOpened():
        print("camera open error")
        return
    ret, image=cap.read()
    if not ret:
        print("frame read error")
        break
    cv2.imshow('CAMERA', image)
    time.sleep(1)
    cv2.imwrite("./image.jpg", image)
    cap.release()
    cv2.destroyAllWindows()


async def alarm(context: ContextTypes.DEFAULT_TYPE) -> None:
    """Send the alarm message."""
    takePhoto()
    job = context.job
    await context.bot.send_message(job.chat_id, text=f"Beep! {job.data} seconds are over!")
    await context.bot.sendPhoto(job.chat_id, photo=open("./image.jpg","rd"))
```









