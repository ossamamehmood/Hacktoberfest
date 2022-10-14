import pygame
from queue import PriorityQueue
import time

BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
GREY = (128, 128, 128)
BLUE = (0, 128, 128)
GREEN = (0, 255, 0)
ORANGE = (255, 165, 0)
YELLOW = (255, 255, 0)
RED = (255, 0, 0)

pygame.init()
clock = pygame.time.Clock()

width = 800
height = 900
gap = 20
rows = cols = width // gap
grid = []
win = pygame.display.set_mode((width, height))
pygame.display.set_caption("Shortest Path Algo Visualizer")


class node:
    def __init__(self, row, col):  # x and y are coordinates of maze
        self.row = row
        self.col = col
        self.x = row * gap
        self.y = col * gap
        self.f = float('inf')  # f, g and h are parameters for A* Algo
        self.g = float('inf')
        self.h = 0
        self.color = WHITE
        self.neighbors = []  # list of all 4 neighbors of any node
        self.dis = float('inf')
        self.vis = False

    def show(self, win):
        pygame.draw.rect(win, self.color, (self.x, self.y, gap, gap))

    def build_wall(self):
        self.color = GREY

    def build_start(self):
        self.color = GREEN

    def build_end(self):
        self.color = RED

    def build_open(self):
        self.color = YELLOW

    def build_closed(self):
        self.color = ORANGE

    def remove_anything(self):
        self.color = WHITE

    def build_path(self):
        self.color = BLUE

    def is_wall(self):
        if self.color == GREY:
            return True

    def get_color(self):
        return self.color

    def get_coordinates(self):
        return self.row, self.col

    def set_neighbors(self):
        self.neighbors = []
        if self.row < rows - 1 and not grid[self.row + 1][self.col].is_wall():  # up
            self.neighbors.append(grid[self.row + 1][self.col])

        if self.row > 0 and not grid[self.row - 1][self.col].is_wall():  # down
            self.neighbors.append(grid[self.row - 1][self.col])

        # right
        if self.col < cols - 1 and not grid[self.row][self.col + 1].is_wall():
            self.neighbors.append(grid[self.row][self.col + 1])

        if self.col > 0 and not grid[self.row][self.col - 1].is_wall():  # left
            self.neighbors.append(grid[self.row][self.col - 1])

    def __lt__(self, other):
        return False


def make_grid():
    for i in range(rows):
        grid.append([])
        for j in range(cols):
            grid[i].append(node(i, j))


def draw_grid(win):  # Filling all screen with white color and then drawing cubes and gridlines again
    win.fill(WHITE)

    # Drawing node squares
    for i in range(rows):
        for j in range(cols):
            grid[i][j].show(win)

    #  Drawing grid lines
    for i in range(rows):
        pygame.draw.line(win, BLACK, (0, i * gap), (width, i * gap))
        for j in range(cols):
            pygame.draw.line(win, BLACK, (j * gap, 0), (j * gap, width))

    # Drawing 3 rectangular buttons at bottom
    pygame.draw.rect(win, BLUE, (100, 820, 100, 50))
    pygame.draw.rect(win, BLUE, (365, 820, 100, 50))
    pygame.draw.rect(win, BLUE, (610, 820, 170, 50))
    font = pygame.font.SysFont('comicsans', 30, True)
    text1 = font.render(' A* ', 1, (0, 0, 0))
    text2 = font.render(' BFS ', 1, (0, 0, 0))
    text3 = font.render(' Clear Canvas ', 1, (0, 0, 0))
    win.blit(text1, (115, 835))
    win.blit(text2, (380, 835))
    win.blit(text3, (610, 835))
    pygame.display.update()


def clear_grid():
    for i in range(rows):
        for j in range(cols):
            grid[i][j].color = WHITE


def convert_coordinates(pos):  # convert pixel position to grid row, column
    x = pos[0] // gap
    y = pos[1] // gap
    return x, y


def h(pos1, pos2):  # h parameter of A* Algo
    a, b = pos1
    c, d = pos2
    return abs(a - c) + abs(b - d)


def construct_path(last_node, cur, start, end):  # construct path at the end
    while cur in last_node:
        if cur != start and cur != end:
            cur.build_path()
        cur = last_node[cur]
        draw_grid(win)


# ASTAR Algorithm
def astar(start, end):
    count = 0
    # priority queue to fetch the smallest f valued node contains touple of (f value, node)
    open_list = PriorityQueue()
    last_node = {}  # dictionary containing the previous visited node

    start.g = 0
    start.h = h(start.get_coordinates(), end.get_coordinates())
    start.f = start.g + start.h

    open_list.put((start.f, count, start))
    open_list_nodes = {start}
    while not open_list.empty():
        for event in pygame.event.get():  # to end program in middle of algorithm
            if event.type == pygame.QUIT:
                pygame.quit()

        cur = open_list.get()[2]
        open_list_nodes.remove(cur)

        if cur == end:
            construct_path(last_node, cur, start, end)
            end.build_end()
            return True

        for neighbor in cur.neighbors:  # for every neighbor
            if neighbor.g > cur.g + 1:  # if its g value is greater than of current
                last_node[neighbor] = cur
                neighbor.g = cur.g + 1
                neighbor.h = h(neighbor.get_coordinates(),
                               end.get_coordinates())
                neighbor.f = neighbor.g + neighbor.h
                if neighbor not in open_list_nodes:  # if node is not in open_list then we add
                    count += 1
                    open_list.put((neighbor.f, count, neighbor))
                    open_list_nodes.add(neighbor)
                    neighbor.build_open()

        draw_grid(win)
        if cur != start and cur != end:
            cur.build_closed()
    return False


# BFS algorithm
def bfs(start, end):
    q = PriorityQueue()
    q.put((0, start))
    last_node = {}
    start.dis = 0
    while not q.empty():
        a = q.get()[1]
        if not a.vis:
            a.vis = True
            for b in grid[a.row][a.col].neighbors:
                if b == end:
                    a.build_closed()
                    construct_path(last_node, a, start, end)
                    return True

                if a.dis + 1 < b.dis and not b.is_wall():
                    b.dis = a.dis + 1
                    q.put((b.dis, b))
                    if not b == start and not b == end and not b.is_wall():
                        last_node[b] = a
                        b.build_open()
        if not a == start and not a == end and not a.is_wall():
            a.build_closed()
        draw_grid(win)


def main():
    clock.tick(24)
    make_grid()

    start = None
    end = None
    run = True
    while run:
        draw_grid(win)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()

            if pygame.mouse.get_pressed()[0]:  # left mouse button
                pos = pygame.mouse.get_pos()
                x = pos[0]
                y = pos[1]

                # This is to check 3 buttons
                if y >= 800:
                    if 820 < y < 870:
                        for i in range(rows):
                            for j in range(cols):
                                grid[i][j].set_neighbors()
                        if 100 < x < 200:
                            astar(start, end)
                        elif 365 < x < 465:
                            bfs(start, end)
                        elif 610 < x < 780:
                            clear_grid()
                            start = None
                            end = None
                    continue

                x, y = convert_coordinates(pos)
                current = grid[x][y]

                if start is None and current != end and current != start:
                    start = current
                    current.build_start()
                elif end is None and current != start:
                    end = current
                    current.build_end()
                elif current != end and current != start:
                    current.build_wall()

            if pygame.mouse.get_pressed()[2]:  # right mouse button
                pos = pygame.mouse.get_pos()
                x, y = convert_coordinates(pos)
                current = grid[x][y]

                if current == start:
                    start = None
                if current == end:
                    end = None
                current.remove_anything()


main()
pygame.quit()
