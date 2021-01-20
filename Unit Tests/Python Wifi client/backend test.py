import WifiBackend
host = "192.168.1.85"
port = 1001
data = ["S","0","0","0"]
servo_pos = 0;
s=WifiBackend.socketSetup(host,port)
print("connected")
while True:
 for char in data:
  print (char)
  WifiBackend.sendMoveData(char,s)
 print("sent")
 data = WifiBackend.receiveSensorData(s)
 print("received")
 print (data)
