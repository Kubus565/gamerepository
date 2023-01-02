import pygame

pygame.init()
window = pygame.display.set_mode((800, 600))

x = 0
y = 0
player = pygame.rect.Rect(x, y, 100, 100) # prostokat xy - polozenie, 100 100 wys szer

run = True
while run:
    pygame.time.Clock().tick(60)
    for event in pygame.event.get():
        if event.type == pygame.QUIT: #jezeli gracz zamknie okno
            run = False

    keys = pygame.key.get_pressed()
    speed = 10
    if keys[pygame.K_RIGHT]:
        x += speed
    if keys[pygame.K_LEFT]:
        x -= speed
    if keys[pygame.K_UP]:
        y -= speed
    if keys[pygame.K_DOWN]:
        y += speed
    player = pygame.rect.Rect(x, y, 100, 100)

    window.fill((24, 164, 240))
    pygame.draw.rect(window, (20, 200, 20), player)
    pygame.display.update()