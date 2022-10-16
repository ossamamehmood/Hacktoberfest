

import pygame
from pygame import mixer
import random
import math
 #initialize the game
pygame.init()

 #create the screen (width,height)
screen = pygame.display.set_mode((800,600))

# background
background = pygame.image.load('C:\\Users\\MY BOOK\\Desktop\\My Files\\p4ye\\New folder\\back.jpg')

#background music
mixer.music.load('C:\\Users\\MY BOOK\\Desktop\\My Files\\p4ye\\New folder\\background.wav')
mixer.music.play(-1)

#TITLE AND iCON
pygame.display.set_caption("SPACE INVADERS")
icon = pygame.image.load('C:\\Users\\MY BOOK\\Desktop\\My Files\\p4ye\\New folder\\alien.png')
pygame.display.set_icon(icon)

#player
playerImg = pygame.image.load('C:\\Users\\MY BOOK\\Desktop\\My Files\\p4ye\\New folder\\space-invaders.png')
playerX = 370
playerY = 480
playerX_change = 0
#playerY_change = 0

#Enemy
enemyImg = []
enemyX = []
enemyY = []
enemyX_change = []
enemyY_change = []
no_of_enemies = 6

for i in range(no_of_enemies):

    enemyImg.append(pygame.image.load('C:\\Users\\MY BOOK\\Desktop\\My Files\\p4ye\\New folder\\death.png'))
    enemyX.append(random.randint(0,735))
    enemyY.append(random.randint(50,150))
    enemyX_change.append(1.0)
    enemyY_change.append(40)


#bullet

#ready  - you cant see the bullet in the screen
#fire - the bullet is currently moving

bulletImg = pygame.image.load('C:\\Users\\MY BOOK\\Desktop\\My Files\\p4ye\\New folder\\bullet.png')
bulletX = 0
bulletY = 480
bulletX_change = 0
bulletY_change = 3
bullet_state = "ready"

# score
score_value = 0
font = pygame.font.Font('C:\\Users\\MY BOOK\\Desktop\\My Files\\p4ye\\New folder\\Yellow Rabbit - Personal Use.otf',64)

textX = 10
textY = 10
#game over text

over_font = pygame.font.Font('C:\\Users\\MY BOOK\\Desktop\\My Files\\p4ye\\New folder\\Yellow Rabbit - Personal Use.otf',256)

def show_score(x,y):
    score = font.render("Score :" + str(score_value),True,(255,255,255))
    screen.blit(score,(x,y))

def game_over_text():
    over_text = font.render("GAME OVER" ,True,(255,255,255))
    screen.blit(over_text,(280,250))


def player(x,y):
    screen.blit(playerImg,(x,y)) #blit means to draw

def enemy(x,y,i):
    screen.blit(enemyImg[i],(x,y)) #blit means to draw

def fire_bullet(x,y):
    global bullet_state
    bullet_state = "fire"
    screen.blit(bulletImg,(x + 16,y + 10))

def isCollision(enemyX,enemyY,bulletX,bulletY):
    distance = math.sqrt(math.pow(enemyX-bulletX,2) + math.pow(enemyY-bulletY,2))
    if distance < 27:
        return True
    else:
        return False


#GAME LOOP 
running = True
while running:

    #RGB = red, green, blue
    screen .fill((0,0,0))
    # background image
    screen.blit(background,(0,0))

    

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        # if keystroke is presses check wheather its right or left
        if event.type == pygame.KEYDOWN:
            
            if event.key == pygame.K_LEFT:
                playerX_change = -3.0
                
            if event.key == pygame.K_RIGHT:
                playerX_change = 3.0
            if event.key == pygame.K_SPACE or event.key == pygame.K_UP:
                if bullet_state is "ready":
                    bullet_Sound = mixer.Sound('C:\\Users\\MY BOOK\\Desktop\\My Files\\p4ye\\New folder\\laser.wav')
                    bullet_Sound.play()
                    #get the current x coordinate  of the spaceship
                    bulletX = playerX
                    fire_bullet(bulletX,bulletY)
                
        if event.type == pygame.KEYUP:
            if event.type == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                playerX_change = 0
        

    # + is because if its + it gets automatically added to the current position
    # checking for  boundary or customizing the movement of the enemy
    playerX += playerX_change

    if playerX <=0:
        playerX = 736
    elif playerX >=736:
        playerX = 0
    
    #enemy movement
    for i in range(no_of_enemies):
        # Game over
        if enemyY[i] > 440:
            for j in range(no_of_enemies):
                enemyY[j] =2000
            game_over_text()
            break

        enemyX[i]+= enemyX_change[i]

        if enemyX[i] <=0:
            enemyX_change[i] = 1.0
            enemyY[i] += enemyY_change[i]
        elif enemyX[i] >=736:
            enemyX_change[i] = -1.0
            enemyY[i] += enemyY_change[i]

         #collision
        collision = isCollision(enemyX[i],enemyY[i],bulletX,bulletY)
        if collision:
            explosion_Sound = mixer.Sound('C:\\Users\\MY BOOK\\Desktop\\My Files\\p4ye\\New folder\\explosion.wav')
            explosion_Sound.play()
            bulletY = 480
            bullet_state = 'ready'
            score_value +=1
            enemyX[i] = random.randint(0,735)
            enemyY[i] = random.randint(50,150)
        enemy(enemyX[i],enemyY[i],i)
    #bullet movement
    if bulletY <=0 :
        bulletY = 480
        bullet_state = "ready"

    if bullet_state is "fire":
        fire_bullet(bulletX ,bulletY)
        bulletY -= bulletY_change

   

    player(playerX,playerY)
    show_score(textX,textY)
    pygame.display.update()
