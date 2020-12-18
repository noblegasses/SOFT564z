import pygame
import os
import time
import random
from collections import defaultdict
pygame.font.init()
WIDTH,HEIGHT = 750,750
WINDOW = pygame.display.set_mode((WIDTH,HEIGHT))
pygame.display.set_caption("GUI")
My_Asset = pygame.transform.scale(pygame.image.load(os.path.join("assets","asset.png")), (WIDTH,HEIGHT))

def GUI():
 run = True
 FPS = 60
 data1 = 69
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
 def redraw_window():
  #place object in the top left corner (0,0)
  WINDOW.blit(My_Asset,(0,0))
  #render(text,anti-alias,(RGB)
  data_label = main_font.render(f"Data:{data1}", 1, (0,255,0))
  WINDOW.blit(data_label,(10,10))
  key_label = main_font.render(f"Key {pressedkey} is pressed.", 1, (255,0,0))
  WINDOW.blit(key_label,(WIDTH-key_label.get_width()-20,HEIGHT-key_label.get_height()-20))
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
  if keylist[pygame.K_d] or keylist[pygame.K_DOWN]:
   pressedkey.append("down")
  if len(pressedkey)==0:
   pressedkey = None
  elif len(pressedkey) == 1:
    pressedkey = pressedkey[0]
  else:
   pressedkey= " and ".join(pressedkey)
  return pressedkey
 while run:
  clock.tick(FPS)
  for event in pygame.event.get():
   if event.type == pygame.QUIT:
    run = False
   pressedkey = parse_keys()
   redraw_window()
    

GUI()
