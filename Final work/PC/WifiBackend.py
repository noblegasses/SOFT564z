import socket
import threading
lock = threading.Lock()
moveData=['S','0','0','0']
InData = [0,0]

def socketSetup(host, port):
 s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
 s.connect((host, port))
 return s
def sendMoveData(data, s):
  #print(data)
  s.send(data.encode())
def receiveSensorData(s):
 data=["",""]
 if (s.recv(1).decode()=="S"):
  for i in range (2):
   while (s.recv(1, socket.MSG_PEEK).decode()!="E"):
    data[i]+=(s.recv(1).decode())
   s.recv(1)#read the end character
 return data
def CloseConnection(s):
    s.close()
def sendReceive(S,sendingData):
 strData = ''.join(sendingData)
 sendMoveData(strData, S)
 return receiveSensorData(S)
 #return [0,0]
     
