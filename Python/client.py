import socket

Host = "192.168.0.85"
Port= 1001
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((Host, Port))
welcomeMsg = ''
while(s.recv(1, socket.MSG_PEEK).decode()!="\r"):
 welcomeMsg+=s.recv(1).decode()
print (welcomeMsg)
hello="Python to ESP!\n\r"
s.send(hello.encode())
data = ''
while(s.recv(1, socket.MSG_PEEK).decode()!="\r"):
 data+=s.recv(1).decode()
s.close()
print ('received', data)
