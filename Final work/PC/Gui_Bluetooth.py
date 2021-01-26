import pygame
import os
import time
import random
import BTBackend
import time
from copy import deepcopy
from collections import defaultdict

pygame.font.init()
WIDTH,HEIGHT = 750,750
KEYWIDTH, KEYHEIGHT = int(WIDTH/10), int(HEIGHT/10)
WINDOW = pygame.display.set_mode((WIDTH,HEIGHT))
Sensordata = []
servo_pos= 90
port = 0
MacAddress = "FC:F5:C4:0F:BD:A2"
pygame.display.set_caption("Bluetooth GUI")
Background = pygame.transform.scale(pygame.image.load(os.path.join("assets","asset.png")), (WIDTH,HEIGHT))
W_unpressed = pygame.transform.scale(pygame.image.load(os.path.join("assets","W_unpressed.png")), (KEYWIDTH,KEYHEIGHT))
A_unpressed = pygame.transform.scale(pygame.image.load(os.path.join("assets","A_unpressed.png")), (KEYWIDTH,KEYHEIGHT))
S_unpressed = pygame.transform.scale(pygame.image.load(os.path.join("assets","S_unpressed.png")), (KEYWIDTH,KEYHEIGHT))
D_unpressed = pygame.transform.scale(pygame.image.load(os.path.join("assets","D_unpressed.png")), (KEYWIDTH,KEYHEIGHT))
V_unpressed = pygame.transform.scale(pygame.image.load(os.path.join("assets","V_unpressed.png")), (KEYWIDTH,KEYHEIGHT))
F_unpressed = pygame.transform.scale(pygame.image.load(os.path.join("assets","F_unpressed.png")), (KEYWIDTH,KEYHEIGHT))
W_pressed = pygame.transform.scale(pygame.image.load(os.path.join("assets","W_pressed.png")), (KEYWIDTH,KEYHEIGHT))
A_pressed = pygame.transform.scale(pygame.image.load(os.path.join("assets","A_pressed.png")), (KEYWIDTH,KEYHEIGHT))
S_pressed = pygame.transform.scale(pygame.image.load(os.path.join("assets","S_pressed.png")), (KEYWIDTH,KEYHEIGHT))
D_pressed = pygame.transform.scale(pygame.image.load(os.path.join("assets","D_pressed.png")), (KEYWIDTH,KEYHEIGHT))
V_pressed = pygame.transform.scale(pygame.image.load(os.path.join("assets","V_pressed.png")), (KEYWIDTH,KEYHEIGHT))
F_pressed = pygame.transform.scale(pygame.image.load(os.path.join("assets","F_pressed.png")), (KEYWIDTH,KEYHEIGHT))


def GUI():
 run = True
 Movedata=["S","0","9","0"]
 oldData=[]
 FPS = 60
 Ultrasonic = 0
 Water_level = 0
 main_font = pygame.font.SysFont("Comic Sans MS", 18)
 #rate of movement of device
 vel=1
 pressedkey=[]
 #a dictonary of usable key input and their results
 keyslist = defaultdict(lambda: None)
 keyslist[(pygame.K_a, pygame.K_LEFT)] = "left"
 keyslist[(pygame.K_d, pygame.K_RIGHT)]= "right"
 keyslist[(pygame.K_w, pygame.K_UP)]:"up"
 keyslist[(pygame.K_s, pygame.K_DOWN)]:"down"
 clock = pygame.time.Clock()
 #functions declared in main stay local to main and can use main's variables as if they were global
 def place_keys(keys):
  PressedSprites={"up":(W_pressed,((WIDTH/2)-W_pressed.get_width(),HEIGHT-(W_pressed.get_width()*2))),
                  "left":(A_pressed,((WIDTH/2)-A_pressed.get_width()*2,HEIGHT-(A_pressed.get_width()))),
                  "down":(S_pressed,((WIDTH/2)-S_pressed.get_width(),HEIGHT-(S_pressed.get_width()))),
                  "right":(D_pressed,((WIDTH/2),HEIGHT-(D_pressed.get_width()))),
                  "F":(F_pressed,((WIDTH-F_pressed.get_width()),HEIGHT-(F_pressed.get_height()*5))),
                  "V":(V_pressed,((WIDTH-V_pressed.get_width()),HEIGHT-(D_pressed.get_height())))
                  }
  for key in keys:
   WINDOW.blit(PressedSprites[key][0],PressedSprites[key][1])

 def Movement(keys):
  def incrementServo():
      global servo_pos
      servo_pos+=1
      if servo_pos>255:
       servo_pos=255
      if servo_pos<10:
       return['0','0']+list(str(servo_pos))
      elif servo_pos<100:
       return['0']+list(str(servo_pos))
      else:
        return list(str(servo_pos))

  def decrementServo():
   global servo_pos
   servo_pos-=1
   if servo_pos<0:
    servo_pos=0
   if servo_pos<10:
    return['0','0']+list(str(servo_pos))
   elif servo_pos<100:
    return['0']+list(str(servo_pos))
   else:
    return list(str(servo_pos))
  pressed={"up":"F",
           "left":"L",
           "down":"B",
           "right":"R",
           "F":incrementServo,
           "V":decrementServo,
           None:"S"
           }
  for key in keys:
   if key == "V" or key == "F":
    Movedata[1::]=pressed[key]()
   else:
    Movedata[0]=pressed[key]
 def redraw_window(key):
  #place object in the top left corner (0,0)
  WINDOW.blit(Background,(0,0))
  Distance_label = main_font.render(f"Distance:{Ultrasonic} mm", 1, (0,255,0))
  WINDOW.blit(Distance_label,(10,10))
  Water_Level_label = main_font.render(f"Water Level:{Water_level}", 1, (0,255,0))
  WINDOW.blit(Water_Level_label,(WIDTH-150,10))
  Servo_label= main_font.render(f"Servo position:{servo_pos}",1,(0,255,0))
  WINDOW.blit(Servo_label,(WIDTH-160,525))
  WINDOW.blit(W_unpressed,((WIDTH/2)-W_unpressed.get_width(),HEIGHT-(W_unpressed.get_height()*2)))
  WINDOW.blit(S_unpressed,((WIDTH/2)-S_unpressed.get_width(),HEIGHT-(S_unpressed.get_height())))
  WINDOW.blit(A_unpressed,((WIDTH/2)-A_unpressed.get_width()*2,HEIGHT-(A_unpressed.get_height())))
  WINDOW.blit(D_unpressed,((WIDTH/2),HEIGHT-(D_unpressed.get_height())))
  WINDOW.blit(F_unpressed,((WIDTH-F_unpressed.get_width()),HEIGHT-(F_unpressed.get_height()*5)))
  WINDOW.blit(V_unpressed,((WIDTH-V_unpressed.get_width()),HEIGHT-(V_unpressed.get_height())))
  if key!=[None]:
   place_keys(key)
  Movement(key)
  
  pygame.display.update()
 def parse_keys():
  pressedkey = []
  keylist = pygame.key.get_pressed()
  if keylist[pygame.K_a] or keylist[pygame.K_LEFT]:
   pressedkey.append("left")
  if keylist[pygame.K_d] or keylist[pygame.K_RIGHT]:
   pressedkey.append("right")
  if keylist[pygame.K_w] or keylist[pygame.K_UP]:
   pressedkey.append("up")
  if keylist[pygame.K_s] or keylist[pygame.K_DOWN]:
   pressedkey.append("down")
  if keylist[pygame.K_f]:
   pressedkey.append("F")
  if keylist[pygame.K_v]:
   pressedkey.append("V");
  if ("up" in pressedkey and "down" in pressedkey):
   pressedkey.remove("up")
   pressedkey.remove("down")
  if ("left" in pressedkey and "right" in pressedkey):
   pressedkey.remove("left")
   pressedkey.remove("right")
  if ("V" in pressedkey and "F" in pressedkey):
   pressedkey.remove("F")
   pressedkey.remove("V")
  if len(pressedkey)==0:
   pressedkey = [None]
  return pressedkey
 startTime= time.perf_counter()
 while run:
  clock.tick(FPS)
  for event in pygame.event.get():
   if event.type == pygame.QUIT:
    run = False
   pressedkey = parse_keys()
  redraw_window(pressedkey)
  if time.perf_counter()-startTime >0.005:
   startTime= time.perf_counter()
   [Ultrasonic, Water_level] =BTBackend.sendReceive(S,Movedata,oldData)
   oldData = deepcopy(Movedata)
 return True
Done = False
while(not Done):
 try:
  S = BTBackend.socketSetup(MacAddress, port)
  Done = GUI()
 except Exception:
  print("Reconnecting")
  BTBackend.CloseConnection(S)
BTBackend.CloseConnection(S)
