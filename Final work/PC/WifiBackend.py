import socket
def socketSetup(host, port):
 s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
 s.connect((host, port))
 return s
def sendMoveData(data, s):
  s.send(data.encode())
def receiveSensorData(s):
 data=[]
 for i in range (8):
  data.append(s.recv(1).decode())
 return data
def CloseConnection(s):
    s.close()

