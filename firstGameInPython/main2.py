import pygame
import os
import time
import random
pygame.font.init()

WIDTH, HEIGHT = 750, 600
WIN = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Moja giera")

#load images
RED_SPACE_SHIP = pygame.image.load(os.path.join("assets", "pixel_ship_red_small.png"))
GREEN_SPACE_SHIP = pygame.image.load(os.path.join("assets", "pixel_ship_green_small.png"))
BLUE_SPACE_SHIP = pygame.image.load(os.path.join("assets", "pixel_ship_blue_small.png"))

#player
YELLOWE_SHIP = pygame.image.load(os.path.join("assets", "pixel_ship_yellow.png"))

RED_LASER = pygame.image.load(os.path.join("assets", "pixel_laser_red.png"))
GREEN_LASER = pygame.image.load(os.path.join("assets", "pixel_laser_green.png"))
BLUE_LASER = pygame.image.load(os.path.join("assets", "pixel_laser_blue.png"))
YELLOW_LASER = pygame.image.load(os.path.join("assets", "pixel_laser_yellow.png"))

#background
BG = pygame.transform.scale(pygame.image.load(os.path.join("assets", "background-black.png")), (WIDTH, WIDTH))

class Ship:
    def __init__(self, x, y, health=100):
        self.x = x
        self.y = y
        self.health = health
        self.ship_img = None
        self.laser_img = None
        self.lasers = []
        self.cool_down_counter = 0

    def draw(self, window):
        window.blit(self.ship_img, (self.x, self.y))
        #pygame.draw.rect(window, (255, 0, 0), (self.x, self.y, 50, 50))



class Player(Ship):
    def __init__(self, x, y, health=100):
        super().__init__(x, y, health)
        self.ship_img = YELLOWE_SHIP
        self.laser_img = YELLOW_LASER
        self.mask = pygame.mask.from_surface(self.ship_img)
        self.max_health = health




def main():
    run= True
    FPS = 60
    level = 1
    lives = 5
    main_font = pygame.font.SysFont("comicsans", 50)

    player_vel = 5
    velX=6
    velY=6
    player = Player(300, 400)

    clock = pygame.time.Clock()

    def redraw_window():
        WIN.blit(BG, (0, 0))
        #draw text
        lives_label = main_font.render(f"Lives: {lives}", 1, (255, 0, 0))
        level_label = main_font.render(f"Level: {level}", 1, (255, 255, 0))

        WIN.blit(lives_label, (10, 10))
        WIN.blit(level_label, (WIDTH - level_label.get_width() - 10, 10))

        player.draw(WIN)
        pygame.display.update()



    while run:
        clock.tick(FPS) # skonczylem na 50:05 Pygame tutorial - Tech with tim
        redraw_window()

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False

        player.x += velX
        player.y += velY
        if player.x >= WIDTH - 50:
            velX = -velX
        if player.x < 0:
            velX = -velX
        if player.y >= HEIGHT - 50:
            velY = -velY
        if player.y < 0:
            velY = -velY


        keys = pygame.key.get_pressed()
        # if keys[pygame.K_a] and player.x - player_vel > 0: #left
        #     player.x -= player_vel
        # if keys[pygame.K_d] and player.x + player_vel + 50 < WIDTH: #right
        #     player.x += player_vel
        # if keys[pygame.K_w] and player.y - player_vel > 0: #up
        #     player.y -= player_vel
        # if keys[pygame.K_s] and player.y + player_vel  + 50 < HEIGHT: #down
        #     player.y += player_vel





main()
