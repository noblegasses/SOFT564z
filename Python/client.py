import socket

Host = "192.168.0.85"
Port= 1001
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((Host, Port))
welcomeMsg = ''
while(s.recv(8, socket.MSG_PEEK)):
 print("reading bus")
 welcomeMsg+=s.recv(8).decode()
print (welcomeMsg)
hello="Python to ESP!"
s.send(hello.encode())
data = ''
while(s.recv(8, socket.MSG_PEEK)):
 data+=s.recv(1024).decode()
s.close()
print ('received', data)
