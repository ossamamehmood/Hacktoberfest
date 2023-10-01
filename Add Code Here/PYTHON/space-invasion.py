# This is only part of the game
# Refer to https://github.com/Hemant-Agrawal/Space-Invasion for more details
import pygame
import random
from pygame import mixer

pygame.init()
screen = pygame.display.set_mode((800, 600))
clock = pygame.time.Clock()

background = pygame.image.load("Images\\space-bg.png")
mixer.music.load("Sound\\background.wav")
mixer.music.play(-1)

icon = pygame.image.load("Images\\globe.png")
pygame.display.set_icon(icon)
pygame.display.set_caption("Space Invasion")
explosion_sound = mixer.Sound("Sound\\explosion.wav")

font72 = pygame.font.Font('freesansbold.ttf', 72)
font32 = pygame.font.Font('freesansbold.ttf', 32)


def isCollison(first, second):
    if first[0] <= second[0] + second[2] and first[0] + first[2] >= second[0]:
        if first[1] <= second[1] + second[2] and first[1] + first[2] >= second[1]:
            explosion_sound.play()
            return True
    return False


def game_over():
    global running
    running = False
    text = font72.render('GAME OVER', True, (255, 255, 255))
    screen.blit(text, (210, 230))


def magazine_show(capacity):
    for i in range(capacity):
        screen.blit(Bullet.img, (760-25*i, 10))


def show_score():
    score = font32.render(f"Score : {score_value}", True, (255, 255, 255))
    screen.blit(score, (10, 10))
    score = font32.render(f"Level : {level_value}", True, (255, 255, 255))
    screen.blit(score, (300, 10))


def level_up():
    global enemies, level_value
    number_of_enemies = 6 + level_value
    enemies = [Enemy() for _ in range(number_of_enemies)]
    level_value += 1


def reloading():
    global reload
    reload = True
    return magazine + 1


class Enemy:
    enemy_id = 0
    img = pygame.image.load('Images\\alien.png')

    def __init__(self):
        Enemy.enemy_id += 1
        self.X = random.randint(0, 736)
        self.Y = random.randint(32, 150)
        self.X_change = 4
        self.Y_change = 64
        self.id = Enemy.enemy_id
        self.size = 64

    def __repr__(self):
        return f"Enemy ID:- {self.id}"

    def show(self, display_object):
        self.X += self.X_change
        display_object.blit(Enemy.img, (self.X, self.Y))

    def move(self):
        if self.X >= 736:
            self.X_change = -4
            self.Y += self.Y_change
        elif self.X <= 0:
            self.X_change = 4
            self.Y += self.Y_change

    def killed(self):
        self.X = random.randint(0, 736)
        self.Y = random.randint(32, 200)


class Player:
    player_id = 0

    def __init__(self):
        Player.player_id += 1
        self.img = pygame.image.load('Images\\spaceship.png')
        self.X = 350
        self.Y = 480
        self.X_change = 0
        self.id = Player.player_id
        self.size = 64

    def __repr__(self):
        return f"Player ID:- {self.id}"

    def show(self, display_object):
        self.X += self.X_change
        if self.X >= 736:
            self.X = 736
        elif self.X <= 0:
            self.X = 0
        display_object.blit(self.img, (self.X, self.Y))

    def move(self, right):
        if right:
            self.X_change = 3
        if not right:
            self.X_change = -3

    def stop(self):
        self.X_change = 0


class Bullet:
    bullet_id = 0
    img = pygame.image.load('Images\\bullet.png')

    def __init__(self):
        Bullet.bullet_id += 1
        self.X = 0
        self.Y = 0
        self.Y_change = 2
        self.id = Bullet.bullet_id
        self.size = 32
        self.state = 'ready'
        self.sound = mixer.Sound("Sound\\laser.wav")

    def __repr__(self):
        return f"Bullet ID:- {self.id}"

    def show(self, display_object):
        if self.Y <= 0:
            self.ready()
        if self.state == 'fired':
            self.Y -= self.Y_change
            display_object.blit(self.img, (self.X, self.Y))

    def fired(self):
        self.state = 'fired'
        self.sound.play()

    def ready(self):
        self.state = 'ready'
        self.Y = 0


reload = False
score_value = 0
level_value = 0
enemies = []
magazine = 0
magazine_size = 8
bullets = [Bullet() for _ in range(magazine_size)]
player = Player()
running = True
while running:
    screen.blit(background, (0, 0))
    if magazine == 0:
        magazine = magazine_size
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_RIGHT:
                player.move(right=True)
            if event.key == pygame.K_LEFT:
                player.move(right=False)
            if event.key == pygame.K_SPACE and magazine > 0:
                if bullets[magazine-1].state == 'ready':
                    magazine -= 1
                    bullets[magazine].X, bullets[magazine].Y = player.X + 16, player.Y
                    bullets[magazine].fired()
        if event.type == pygame.KEYUP:
            if event.key == pygame.K_RIGHT or event.key == pygame.K_LEFT:
                player.stop()
    show_score()
    if len(enemies) == 0:
        level_up()
    for enemy in enemies:
        enemy.move()
        enemy.show(screen)
        if isCollison((enemy.X, enemy.Y, enemy.size), (player.X, player.Y, player.size)):
            game_over()
    player.show(screen)
    for bullet in bullets:
        bullet.show(screen)
        for enemy in enemies:
            if isCollison((enemy.X, enemy.Y, enemy.size), (bullet.X, bullet.Y, bullet.size)):
                bullet.ready()
                score_value += 1
                enemies.remove(enemy)
    magazine_show(len([1 for bullet in bullets if bullet.state == 'ready']))
    clock.tick(60)
    pygame.display.update()
pygame.quit()
