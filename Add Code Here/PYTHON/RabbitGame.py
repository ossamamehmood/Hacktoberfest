import random
import os

# Constants for game elements
RABBIT = 'r'
RABBIT_WITH_CARROT = 'R'
CARROT = 'c'
RABBIT_HOLE = 'O'
PATHWAY_STONE = '-'


# Create a 2D map

def create_map(map_size, num_carrots, num_rabbit_holes):
    
    game_map = [[PATHWAY_STONE for _ in range(map_size)] for _ in range(map_size)]

    # Place rabbit
    rabbit_x, rabbit_y = random.randint(
        0, map_size - 1), random.randint(0, map_size - 1)
    game_map[rabbit_x][rabbit_y] = RABBIT

    # Place carrots
    for _ in range(num_carrots):
        carrot_x, carrot_y = random.randint(
            0, map_size - 1), random.randint(0, map_size - 1)
        while game_map[carrot_x][carrot_y] != PATHWAY_STONE:
            carrot_x, carrot_y = random.randint(
                0, map_size - 1), random.randint(0, map_size - 1)
        game_map[carrot_x][carrot_y] = CARROT

    # Place rabbit holes
    for _ in range(num_rabbit_holes):
        hole_x, hole_y = random.randint(
            0, map_size - 1), random.randint(0, map_size - 1)
        while game_map[hole_x][hole_y] != PATHWAY_STONE:
            hole_x, hole_y = random.randint(
                0, map_size - 1), random.randint(0, map_size - 1)
        game_map[hole_x][hole_y] = RABBIT_HOLE

    return game_map


# Find the position of the rabbit on the map

def find_rabbit_position(game_map, map_size):
    for i in range(map_size):
        for j in range(map_size):
            if game_map[i][j] == RABBIT or game_map[i][j] == RABBIT_WITH_CARROT:
                return i, j


# Display the game map

def display_map(game_map):
    for row in game_map:
        print(' '.join(row))


# Check if the move is within the boundaries of the map

def is_valid_move(game_map, x, y, map_size):
    if 0 <= x < map_size and 0 <= y < map_size and game_map[x][y] != CARROT and game_map[x][y] != RABBIT_HOLE:
        return True

    return False


# Pick up a carrot if available at the current position

def pick_carrot(game_map, x, y, counter, map_size):
    if 0 < x < map_size-1 and 0 < y < map_size-1:
        if game_map[x][y] == RABBIT_WITH_CARROT and (game_map[x][y+1] == RABBIT_HOLE or game_map[x][y-1] == RABBIT_HOLE or game_map[x+1][y] == RABBIT_HOLE or game_map[x-1][y] == RABBIT_HOLE):
            game_map[x][y] = PATHWAY_STONE
            return counter+1
        else:
            if game_map[x][y+1] == CARROT and game_map[x][y] == RABBIT:
                game_map[x][y] = PATHWAY_STONE
                game_map[x][y+1] = RABBIT_WITH_CARROT
                return counter+1
            elif game_map[x][y-1] == CARROT and game_map[x][y] == RABBIT:
                game_map[x][y] = PATHWAY_STONE
                game_map[x][y-1] = RABBIT_WITH_CARROT
                return counter+1
            elif game_map[x+1][y] == CARROT and game_map[x][y] == RABBIT:
                game_map[x][y] = PATHWAY_STONE
                game_map[x+1][y] = RABBIT_WITH_CARROT
                return counter+1
            elif game_map[x-1][y] == CARROT and game_map[x][y] == RABBIT:
                game_map[x][y] = PATHWAY_STONE
                game_map[x-1][y] = RABBIT_WITH_CARROT
                return counter+1
    elif x == 0 and y == 0:
        if game_map[x][y] == RABBIT_WITH_CARROT and (game_map[x][y+1] == RABBIT_HOLE or game_map[x+1][y] == RABBIT_HOLE):
            game_map[x][y] = PATHWAY_STONE
            return counter+1
        else:
            if game_map[x][y+1] == CARROT and game_map[x][y] == RABBIT:
                game_map[x][y] = PATHWAY_STONE
                game_map[x][y+1] = RABBIT_WITH_CARROT
                return counter+1
            elif game_map[x+1][y] == CARROT and game_map[x][y] == RABBIT:
                game_map[x][y] = PATHWAY_STONE
                game_map[x+1][y] = RABBIT_WITH_CARROT
                return counter+1
    elif x == map_size-1 and y == map_size-1:
        if game_map[x][y] == RABBIT_WITH_CARROT and (game_map[x][y-1] == RABBIT_HOLE or game_map[x-1][y] == RABBIT_HOLE):
            game_map[x][y] = PATHWAY_STONE
            return counter+1
        else:
            if game_map[x][y-1] == CARROT and game_map[x][y] == RABBIT:
                game_map[x][y] = PATHWAY_STONE
                game_map[x][y-1] = RABBIT_WITH_CARROT
                return counter+1
            elif game_map[x-1][y] == CARROT and game_map[x][y] == RABBIT:
                game_map[x][y] = PATHWAY_STONE
                game_map[x-1][y] = RABBIT_WITH_CARROT
                return counter+1
    elif x == 0 and y == map_size-1:
        if game_map[x][y] == RABBIT_WITH_CARROT and (game_map[x][y-1] == RABBIT_HOLE or game_map[x+1][y] == RABBIT_HOLE):
            game_map[x][y] = PATHWAY_STONE
            return counter+1
        else:
            if game_map[x][y-1] == CARROT and game_map[x][y] == RABBIT:
                game_map[x][y] = PATHWAY_STONE
                game_map[x][y-1] = RABBIT_WITH_CARROT
                return counter+1
            elif game_map[x+1][y] == CARROT and game_map[x][y] == RABBIT:
                game_map[x][y] = PATHWAY_STONE
                game_map[x+1][y] = RABBIT_WITH_CARROT
                return counter+1
    elif x == map_size-1 and y == 0:
        if game_map[x][y] == RABBIT_WITH_CARROT and (game_map[x][y+1] == RABBIT_HOLE or game_map[x-1][y] == RABBIT_HOLE):
            game_map[x][y] = PATHWAY_STONE
            return counter+1
        else:
            if game_map[x][y+1] == CARROT and game_map[x][y] == RABBIT:
                game_map[x][y] = PATHWAY_STONE
                game_map[x][y+1] = RABBIT_WITH_CARROT
                return counter+1
            elif game_map[x-1][y] == CARROT and game_map[x][y] == RABBIT:
                game_map[x][y] = PATHWAY_STONE
                game_map[x-1][y] = RABBIT_WITH_CARROT
                return counter+1
    else:
        if x == 0:
            if game_map[x][y] == RABBIT_WITH_CARROT and (game_map[x][y+1] == RABBIT_HOLE or game_map[x][y-1] == RABBIT_HOLE or game_map[x+1][y] == RABBIT_HOLE):
                game_map[x][y] = PATHWAY_STONE
                return counter+1
            else:
                if game_map[x][y+1] == CARROT and game_map[x][y] == RABBIT:
                    game_map[x][y] = PATHWAY_STONE
                    game_map[x][y+1] = RABBIT_WITH_CARROT
                    return counter+1
                elif game_map[x][y-1] == CARROT and game_map[x][y] == RABBIT:
                    game_map[x][y] = PATHWAY_STONE
                    game_map[x][y-1] = RABBIT_WITH_CARROT
                    return counter+1
                elif game_map[x+1][y] == CARROT and game_map[x][y] == RABBIT:
                    game_map[x][y] = PATHWAY_STONE
                    game_map[x+1][y] = RABBIT_WITH_CARROT
                    return counter+1
        elif y == 0:
            if game_map[x][y] == RABBIT_WITH_CARROT and (game_map[x][y+1] == RABBIT_HOLE or game_map[x+1][y] == RABBIT_HOLE or game_map[x-1][y] == RABBIT_HOLE):
                game_map[x][y] = PATHWAY_STONE
                return counter+1
            else:
                if game_map[x][y+1] == CARROT and game_map[x][y] == RABBIT:
                    game_map[x][y] = PATHWAY_STONE
                    game_map[x][y+1] = RABBIT_WITH_CARROT
                    return counter+1
                elif game_map[x+1][y] == CARROT and game_map[x][y] == RABBIT:
                    game_map[x][y] = PATHWAY_STONE
                    game_map[x+1][y] = RABBIT_WITH_CARROT
                    return counter+1
                elif game_map[x-1][y] == CARROT and game_map[x][y] == RABBIT:
                    game_map[x][y] = PATHWAY_STONE
                    game_map[x-1][y] = RABBIT_WITH_CARROT
                    return counter+1
        elif x == map_size-1:
            if game_map[x][y] == RABBIT_WITH_CARROT and (game_map[x][y+1] == RABBIT_HOLE or game_map[x][y-1] == RABBIT_HOLE or game_map[x-1][y] == RABBIT_HOLE):
                game_map[x][y] = PATHWAY_STONE
                return counter+1
            else:
                if game_map[x][y+1] == CARROT and game_map[x][y] == RABBIT:
                    game_map[x][y] = PATHWAY_STONE
                    game_map[x][y+1] = RABBIT_WITH_CARROT
                    return counter+1
                elif game_map[x][y-1] == CARROT and game_map[x][y] == RABBIT:
                    game_map[x][y] = PATHWAY_STONE
                    game_map[x][y-1] = RABBIT_WITH_CARROT
                    return counter+1
                elif game_map[x-1][y] == CARROT and game_map[x][y] == RABBIT:
                    game_map[x][y] = PATHWAY_STONE
                    game_map[x-1][y] = RABBIT_WITH_CARROT
                    return counter+1
        elif y == map_size-1:
            if game_map[x][y] == RABBIT_WITH_CARROT and (game_map[x][y-1] == RABBIT_HOLE or game_map[x+1][y] == RABBIT_HOLE or game_map[x-1][y] == RABBIT_HOLE):
                game_map[x][y] = PATHWAY_STONE
                return counter+1
            else:
                if game_map[x][y-1] == CARROT and game_map[x][y] == RABBIT:
                    game_map[x][y] = PATHWAY_STONE
                    game_map[x][y-1] = RABBIT_WITH_CARROT
                    return counter+1
                elif game_map[x+1][y] == CARROT and game_map[x][y] == RABBIT:
                    game_map[x][y] = PATHWAY_STONE
                    game_map[x+1][y] = RABBIT_WITH_CARROT
                    return counter+1
                elif game_map[x-1][y] == CARROT and game_map[x][y] == RABBIT:
                    game_map[x][y] = PATHWAY_STONE
                    game_map[x-1][y] = RABBIT_WITH_CARROT
                    return counter+1


# Jump over a rabbit hole if adjacent

def jump_rabbit_hole(game_map, x, y, map_size):
    if 0 < x < map_size-2 and 0 < y < map_size-2:
        if game_map[x][y+1] == RABBIT_HOLE and game_map[x][y+2] != RABBIT_HOLE:
            current_rabbit = game_map[x][y]
            game_map[x][y] = PATHWAY_STONE
            game_map[x][y+2] = current_rabbit
        elif game_map[x][y-1] == RABBIT_HOLE and game_map[x][y-2] != RABBIT_HOLE:
            current_rabbit = game_map[x][y]
            game_map[x][y] = PATHWAY_STONE
            game_map[x][y-2] = current_rabbit
        elif game_map[x+1][y] == RABBIT_HOLE and game_map[x+2][y] != RABBIT_HOLE:
            current_rabbit = game_map[x][y]
            game_map[x][y] = PATHWAY_STONE
            game_map[x+2][y] = current_rabbit
        elif game_map[x-1][y] == RABBIT_HOLE and game_map[x-2][y] != RABBIT_HOLE:
            current_rabbit = game_map[x][y]
            game_map[x][y] = PATHWAY_STONE
            game_map[x-2][y] = current_rabbit

    elif x == 0 and y == 0:
        if game_map[x][y+1] == RABBIT_HOLE and game_map[x][y+2] != RABBIT_HOLE:
            current_rabbit = game_map[x][y]
            game_map[x][y] = PATHWAY_STONE
            game_map[x][y+2] = current_rabbit
        elif game_map[x+1][y] == RABBIT_HOLE and game_map[x+2][y] != RABBIT_HOLE:
            current_rabbit = game_map[x][y]
            game_map[x][y] = PATHWAY_STONE
            game_map[x+2][y] = current_rabbit

    elif x == map_size-1 and y == map_size-1 and game_map[x][y-2] != RABBIT_HOLE:
        if game_map[x][y-1] == RABBIT_HOLE:
            current_rabbit = game_map[x][y]
            game_map[x][y] = PATHWAY_STONE
            game_map[x][y-2] = current_rabbit
        elif game_map[x-1][y] == RABBIT_HOLE and game_map[x-2][y] != RABBIT_HOLE:
            current_rabbit = game_map[x][y]
            game_map[x][y] = PATHWAY_STONE
            game_map[x-2][y] = current_rabbit

    elif x == 0 and y == map_size-1:
        if game_map[x][y-1] == RABBIT_HOLE and game_map[x][y-2] != RABBIT_HOLE:
            current_rabbit = game_map[x][y]
            game_map[x][y] = PATHWAY_STONE
            game_map[x][y-2] = current_rabbit
        elif game_map[x+1][y] == RABBIT_HOLE and game_map[x+2][y] != RABBIT_HOLE:
            current_rabbit = game_map[x][y]
            game_map[x][y] = PATHWAY_STONE
            game_map[x+2][y] = current_rabbit

    elif x == map_size-1 and y == 0:
        if game_map[x][y+1] == RABBIT_HOLE and game_map[x][y+2] != RABBIT_HOLE:
            current_rabbit = game_map[x][y]
            game_map[x][y] = PATHWAY_STONE
            game_map[x][y+2] = current_rabbit
        elif game_map[x-1][y] == RABBIT_HOLE and game_map[x-2][y] != RABBIT_HOLE:
            current_rabbit = game_map[x][y]
            game_map[x][y] = PATHWAY_STONE
            game_map[x-2][y] = current_rabbit

    else:

        if x < 2:
            if game_map[x][y+1] == RABBIT_HOLE and game_map[x][y+2] != RABBIT_HOLE:
                current_rabbit = game_map[x][y]
                game_map[x][y] = PATHWAY_STONE
                game_map[x][y+2] = current_rabbit
            elif game_map[x][y-1] == RABBIT_HOLE and game_map[x][y-2] != RABBIT_HOLE:
                current_rabbit = game_map[x][y]
                game_map[x][y] = PATHWAY_STONE
                game_map[x][y-2] = current_rabbit
            elif game_map[x+1][y] == RABBIT_HOLE and game_map[x+2][y] != RABBIT_HOLE:
                current_rabbit = game_map[x][y]
                game_map[x][y] = PATHWAY_STONE
                game_map[x+2][y] = current_rabbit

        elif map_size-3 < x < map_size:
            if game_map[x][y+1] == RABBIT_HOLE and game_map[x][y+2] != RABBIT_HOLE:
                current_rabbit = game_map[x][y]
                game_map[x][y] = PATHWAY_STONE
                game_map[x][y+2] = current_rabbit
            elif game_map[x][y-1] == RABBIT_HOLE and game_map[x][y-2] != RABBIT_HOLE:
                current_rabbit = game_map[x][y]
                game_map[x][y] = PATHWAY_STONE
                game_map[x][y-2] = current_rabbit
            elif game_map[x-1][y] == RABBIT_HOLE and game_map[x-2][y] != RABBIT_HOLE:
                current_rabbit = game_map[x][y]
                game_map[x][y] = PATHWAY_STONE
                game_map[x-2][y] = current_rabbit

        elif y < 2:
            if game_map[x][y+1] == RABBIT_HOLE and game_map[x][y+2] != RABBIT_HOLE:
                current_rabbit = game_map[x][y]
                game_map[x][y] = PATHWAY_STONE
                game_map[x][y+2] = current_rabbit
            elif game_map[x+1][y] == RABBIT_HOLE and game_map[x+2][y] != RABBIT_HOLE:
                current_rabbit = game_map[x][y]
                game_map[x][y] = PATHWAY_STONE
                game_map[x+2][y] = current_rabbit
            elif game_map[x-1][y] == RABBIT_HOLE and game_map[x-2][y] != RABBIT_HOLE:
                current_rabbit = game_map[x][y]
                game_map[x][y] = PATHWAY_STONE
                game_map[x-2][y] = current_rabbit

        elif map_size-3 < y < map_size:
            if game_map[x][y-1] == RABBIT_HOLE and game_map[x][y-2] != RABBIT_HOLE:
                current_rabbit = game_map[x][y]
                game_map[x][y] = PATHWAY_STONE
                game_map[x][y-2] = current_rabbit
            elif game_map[x+1][y] == RABBIT_HOLE and game_map[x+2][y] != RABBIT_HOLE:
                current_rabbit = game_map[x][y]
                game_map[x][y] = PATHWAY_STONE
                game_map[x+2][y] = current_rabbit
            elif game_map[x-1][y] == RABBIT_HOLE and game_map[x-2][y] != RABBIT_HOLE:
                current_rabbit = game_map[x][y]
                game_map[x][y] = PATHWAY_STONE
                game_map[x-2][y] = current_rabbit


# Main game loop

def main():

    try:
        # Initialize game parameters
        map_size = int(input("Enter the size of the grid (minimum 10): "))
        num_carrots = int(input("Enter the number of carrots (minimum 2): "))
        num_rabbit_holes = int(input("Enter the number of rabbit holes (minimum 2): "))

        while map_size < 10:
            map_size = int(input("Please enter grid size greater than 9: "))

        while num_carrots <= 1:
            num_carrots = int(input("Please enter number of carrots greater than 1: "))

        while num_rabbit_holes <= 1:
            num_rabbit_holes = int(input("Please enter number of rabbit holes greater than 1: "))
            
        game_map = create_map(map_size, num_carrots, num_rabbit_holes)
        counter = 0

        while True:

            if counter==2:
                display_map(game_map)
                print("*************************")
                print("Congratulations! You won!")
                print("*************************")
                break

            display_map(game_map)
            rabbit_x, rabbit_y = find_rabbit_position(game_map, map_size)
            move = input("Enter your move (a/d/w/s/p/j/q): ").lower()

            if move == 'q':
                print("Exiting the game.")
                break

            elif move == 'p' or move == 'j':
                os.system('cls')
                if move == 'p':
                    co = pick_carrot(game_map, rabbit_x, rabbit_y, counter, map_size)
                    counter = co
                elif move == 'j':
                    jump_rabbit_hole(game_map, rabbit_x, rabbit_y, map_size)

            else:
                new_x, new_y = rabbit_x, rabbit_y
                m = {'a', 'd', 'w', 's', 'wd', 'dw',
                    'wa', 'aw', 'as', 'sa', 'sd', 'ds'}
                if move in m:
                    if move == 'a':
                        new_y -= 1
                    elif move == 'd':
                        new_y += 1
                    elif move == 'w':
                        new_x -= 1
                    elif move == 's':
                        new_x += 1
                    elif move == 'wd' or move == 'dw':
                        new_x -= 1
                        new_y += 1
                    elif move == 'wa' or move == 'aw':
                        new_x -= 1
                        new_y -= 1
                    elif move == 'as' or move == 'sa':
                        new_x += 1
                        new_y -= 1
                    elif move == 'sd' or move == 'ds':
                        new_x += 1
                        new_y += 1

                    if is_valid_move(game_map, new_x, new_y, map_size):
                        current_rabbit = game_map[rabbit_x][rabbit_y]
                        game_map[rabbit_x][rabbit_y] = PATHWAY_STONE
                        rabbit_x, rabbit_y = new_x, new_y
                        game_map[rabbit_x][rabbit_y] = current_rabbit
                        os.system('cls')
                    os.system('cls')
                else:
                    os.system('cls')
                    print("Invalid move. Try again.")

    except Exception as e:
        print("Wrong key press, ", e)
        print("**********************************************************")
        print("Restart the game...!")
        print("**********************************************************")

if __name__ == "__main__":
    os.system('cls')
    print('Instructions:')
    print('Press Enter to play the game; Press any other key to Quit.')
    print('Repeat the same after every play.')
    key = input()
    if key == "":
        main()



