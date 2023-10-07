import sys, time, string

messsage = """Hello, world!""".upper()

GREEN = '\033[0;91m\033[0;101m'
DEFAULT = '\033[0m'
BOLD = '\033[1m'

for i in range(len(messsage) + 1):
    new_msg = messsage[:i]

    if i == len(messsage): 
        print(new_msg, end="\n")
        break
    else: print(new_msg, end="\r")

    for j in string.ascii_uppercase:
        if (messsage[i] == j):
            new_msg = new_msg + j
            break
        print(f"{new_msg}{GREEN}{BOLD}{j}{DEFAULT}", end="\r")

    time.sleep(0.08)

