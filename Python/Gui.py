import pygame
import os
import time
import random
WIDTH,HEIGHT = 750,750
WINDOW = pygame.display.set_mode((WIDTH,HEIGHT))
pygame.display.set_caption("GUI")
My_Asset = pygame.image.load(os.path.join("assets","asset.png"))

def GUI():
 run = True
 FPS = 30
 clock = pygame.time.Clock()
 while run:
  clock.tick(FPS)

  for event in pygame.event.get():
   if event.type == pygame.QUIT:
    run = False
GUI()
