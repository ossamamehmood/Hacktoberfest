import random

num = random.randint(1,99)


#move=7
def start(move):
    print(f"you have {move} move left")

    if move == 0:
        print("Sorry you don't have enough move to play this game")
        print(f"answer is {num}")
        quit()

    ans = int(input("enter the number:-"))

    if ans< num:
        print(f"number is greater the {ans}")
        move = move-1
        start(move)

    elif ans> num:
        print(f"number is smaller then this {ans}")
        move = move-1
        start(move)

    elif num == ans:
        print(f"you guess correct answer.")
        print(f"congrats you win this game for {move} Move.")


if __name__ == '__main__':
    print("-----------------------------")
    print("Welcome to number guess game")
    print("-----------------------------")
    print("number between 1 to 99 ")
    move=7
    start(move)