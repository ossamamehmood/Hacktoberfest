import pygame
import random

pygame.init()

width, height = 640, 480
window = pygame.display.set_mode((width, height))
pygame.display.set_caption("Snake Game")


BLACK = (0, 0, 0)
GREEN = (0, 255, 0)
RED = (255, 0, 0)


class Snake:
    def __init__(self):
        self.size = 1
        self.segments = [(width // 2, height // 2)]
        self.direction = random.choice(["UP", "DOWN", "LEFT", "RIGHT"])

    def move(self):
        x, y = self.segments[0]
        if self.direction == "UP":
            y -= 10
        elif self.direction == "DOWN":
            y += 10
        elif self.direction == "LEFT":
            x -= 10
        elif self.direction == "RIGHT":
            x += 10
        self.segments.insert(0, (x, y))
        if len(self.segments) > self.size:
            self.segments.pop()

    def change_direction(self, direction):
        if direction == "UP" and self.direction != "DOWN":
            self.direction = "UP"
        elif direction == "DOWN" and self.direction != "UP":
            self.direction = "DOWN"
        elif direction == "LEFT" and self.direction != "RIGHT":
            self.direction = "LEFT"
        elif direction == "RIGHT" and self.direction != "LEFT":
            self.direction = "RIGHT"

    def draw(self):
        for segment in self.segments:
            pygame.draw.rect(window, GREEN, (segment[0], segment[1], 10, 10))

    def check_collision(self):
        head = self.segments[0]
        if head[0] < 0 or head[0] >= width or head[1] < 0 or head[1] >= height:
            return True
        for segment in self.segments[1:]:
            if segment == head:
                return True
        return False


class Food:
    def __init__(self):
        self.position = (
            random.randint(0, width // 10 - 1) * 10,
            random.randint(0, height // 10 - 1) * 10,
        )

    def draw(self):
        pygame.draw.rect(window, RED, (self.position[0], self.position[1], 10, 10))


snake = Snake()
food = Food()


clock = pygame.time.Clock()

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP:
                snake.change_direction("UP")
            elif event.key == pygame.K_DOWN:
                snake.change_direction("DOWN")
            elif event.key == pygame.K_LEFT:
                snake.change_direction("LEFT")
            elif event.key == pygame.K_RIGHT:
                snake.change_direction("RIGHT")

    snake.move()

    if snake.segments[0] == food.position:
        snake.size += 1
        food.position = (
            random.randint(0, width // 10 - 1) * 10,
            random.randint(0, height // 10 - 1) * 10,
        )

    if snake.check_collision():
        running = False

    window.fill(BLACK)
    snake.draw()
    food.draw()
    pygame.display.flip()

    clock.tick(10)

pygame.quit()
