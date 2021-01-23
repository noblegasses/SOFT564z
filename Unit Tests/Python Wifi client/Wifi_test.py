import WifiBackend
import time
host = "192.168.1.85"
port =1001
S = WifiBackend.socketSetup(host, port)
startTime= time.perf_counter()
while True:
 if time.perf_counter()-startTime >0.005:
  startTime= time.perf_counter()
  print(WifiBackend.sendReceive(S,['S','2','5','5'],['S','2','5','5']))
