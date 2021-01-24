import socket
moveData=['S','0','0','0']
InData = [0,0]

def socketSetup(host, port):
 s = socket.socket(socket.AF_BLUETOOTH, socket.SOCK_STREAM, socket.BTPROTO_RFCOMM)
 s.connect((host, port))
 return s
def sendMoveData(data, s):
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
def sendReceive(S,sendingData,oldData):
 if sendingData != oldData:
  strData = ''.join(sendingData)
  sendMoveData(strData, S)
 return receiveSensorData(S)
