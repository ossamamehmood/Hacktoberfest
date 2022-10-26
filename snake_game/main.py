import pygame
import time
from pygame.locals import *
import random

size = 40


class Apple:
    def __init__(self, parent_screen):
        self.image = pygame.image.load("resources/apple.jpg").convert()
        self.parent_screen = parent_screen
        self.x = size * 3
        self.y = size * 3

    def draw(self):
        self.parent_screen.blit(self.image, (self.x, self.y))
        pygame.display.flip()

    def move(self):
        self.x = random.randint(1, 18) * size
        self.y = random.randint(1, 18) * size


class Snake:
    def __init__(self, parent_screen, length):
        self.length = length
        self.parent_screen = parent_screen
        self.block = pygame.image.load("resources/block.jpg").convert()
        self.x = [size] * length
        self.y = [size] * length
        self.direction = "down"

    def increase_length(self):
        self.length += 1
        self.x.append((-1))
        self.y.append((-1))

    def draw(self):
        self.parent_screen.fill((119, 235, 52))
        for i in range(self.length):
            self.parent_screen.blit(self.block, (self.x[i], self.y[i]))
        pygame.display.flip()

    def move_up(self):
        self.direction = "up"

    def move_down(self):
        self.direction = "down"

    def move_right(self):
        self.direction = "right"

    def move_left(self):
        self.direction = "left"

    def walk(self):
        for i in range(self.length - 1, 0, -1):
            self.x[i] = self.x[i - 1]
            self.y[i] = self.y[i - 1]
        if self.direction == "down":
            self.y[0] += size
        if self.direction == "up":
            self.y[0] -= size
        if self.direction == "right":
            self.x[0] += size
        if self.direction == "left":
            self.x[0] -= size
        self.draw()


class Game:
    def __init__(self):
        pygame.init()
        self.score = 0
        self.speed = 20
        self.surface = pygame.display.set_mode((800, 800))
        self.surface.fill((119, 235, 52))
        self.snake = Snake(self.surface, 4)
        self.snake.draw()
        self.apple = Apple(self.surface)
        self.apple.draw()
        pygame.display.flip()

    def play(self):
        self.snake.walk()
        self.apple.draw()
        self.display_score()
        pygame.display.flip()
        if self.is_collision(self.snake.x[0], self.snake.y[0], self.apple.x, self.apple.y):
            self.snake.increase_length()
            self.apple.move()
            self.score += 1
            if self.speed < 80:
                self.speed += 2
        for i in range(3, self.snake.length):
            if self.is_collision(self.snake.x[0], self.snake.y[0], self.snake.x[i], self.snake.y[i]):
                raise "Game Over"
        if self.snake.x[0] > 800 or self.snake.y[0] > 800:
            raise "Game Over"
        if self.snake.x[0] < 0 or self.snake.y[0] < 0:
            raise "Game Over"

    def reset(self):
        self.score = 0
        self.speed = 20
        self.snake = Snake(self.surface, 4)
        self.apple = Apple(self.surface)
        pygame.display.flip()

    def game_over(self):
        self.surface.fill((119, 235, 52))
        font = pygame.font.SysFont('arial', 30)
        l1 = font.render(f"Game Over !! score: {self.score} ", True, (0, 0, 0))
        self.surface.blit(l1, (200, 300))
        l2 = font.render(" To restart the game press Enter ", True, (0, 0, 0))
        self.surface.blit(l2, (200, 350))
        l3 = font.render(" To Exit press Esc ", True, (0, 0, 0))
        self.surface.blit(l3, (200, 400))
        pygame.display.flip()

    def display_score(self):


        font = pygame.font.SysFont('arial', 30)
        score = font.render(f"score: {self.score} ", True, (0, 0, 0))
        self.surface.blit(score, (650, 10))
        meter = font.render(f"speed: {self.speed} ", True, (0, 0, 0))
        self.surface.blit(meter, (650, 50))

    def is_collision(self, x1, y1, x2, y2):
        if x1 >= x2 and x1 < x2 + size:
            if y1 >= y2 and y1 < y2 + size:
                return True

    def run(self):
        running = True
        pause = False
        speed = 0.2
        while running:
            if speed > 0.05:
                speed = 0.2 - self.score * 0.005
            for event in pygame.event.get():
                if event.type == KEYDOWN:
                    if event.key == K_SPACE:
                        if not pause:
                            pause = True
                        else:
                            pause = False
                    if event.key == K_RETURN:
                        self.reset()
                        speed =0.2
                        pause = False
                    if event.key == K_UP:
                        self.snake.move_up()
                    if event.key == K_DOWN:
                        self.snake.move_down()
                    if event.key == K_LEFT:
                        self.snake.move_left()
                    if event.key == K_RIGHT:
                        self.snake.move_right()
                    if event.key == K_ESCAPE:
                        running = False
            try:
                if pause is not True:
                    self.play()

            except :
                self.game_over()
                pause = True
            time.sleep(speed)


if __name__ == "__main__":
    game = Game()
    game.run()
