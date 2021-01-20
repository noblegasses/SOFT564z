import WifiBackend
host = "192.168.1.85"
port =1001
S = WifiBackend.socketSetup(host, port)
Move = "S000"
for char in Move:
 WifiBackend.sendMoveData(char, s)
print(WifiBackend
