import random
import termcolor
from termcolor import colored
print(colored("*******************************","green"))
print(colored("*******************************","green"))
print(colored("************HANGMAN************",'blue'))
print(colored("*******************************","green"))
print(colored("*******************************","green"))
name=input(colored("ENTER THE NAME TO PLAY HANGMAN: ",'blue'))
print(colored("Hi {} welcome to HANGMAN".format(name),'red'))
print(colored("Enter 1 for play easy leval HANGMAN","yellow"))
print(colored("Enter 2 for play hard leval HANGMAN",'yellow'))
choice=input(colored('Enter the choice:','blue'))
if choice!='1' and choice!='2':
    print("Wrong input")
    exit(0)
main_list=['MOVIE','FRUIT','PROGRAMMING_LANGUAGE']
random.shuffle(main_list)
if main_list[0]=='FRUIT':
    fruit = ['APPLE', 'MANGO', 'GUAVA', 'LITCHI', 'BANANA', 'ORANGE', 'COCONUT', 'BLACKPLUM','JACKFRUIT','PINEAPPLE','BERRY' ]
    random.shuffle(fruit)
    answer = fruit[1]
    compiler_answer = list(answer)
    print(colored("Guess the name of fruit:", "green"))
elif main_list[0]=='MOVIE':
    movie = ['RACE3', 'BAGHI2', 'RAID', 'PARI', 'PARMANU', 'PADMAN', 'PADMAVAT']
    random.shuffle(movie)
    answer = movie[1]
    compiler_answer = list(answer)
    print(colored("Guess the name of movie(relise 2018):", "magenta"))

elif main_list[0]=='PROGRAMMING_LANGUAGE':
    programming_language = ['ANDROID', 'C++', 'JAVA', 'PYTHON', 'SHIFT', 'JAVASCRIPT', 'PHP', 'HTML', 'KOTLIN', 'JSON','AJAX','JQUERY']
    random.shuffle(programming_language)
    answer = programming_language[1]
    compiler_answer = list(answer)
    print(colored("Guess the name of programming_language:", "blue"))

display=[]
display.extend(compiler_answer)
ex_it=1
count=0
length=len(compiler_answer)
if choice=='1':
    for i in range(len(display)):
        display[i]=" - "
    q = []
    for i in range(len(compiler_answer)):
        q.append(i)
    random.shuffle(q)
    a = q[0]
    guess=compiler_answer[a]
    guess = guess.upper()
    for i in range(len(compiler_answer)):
        if compiler_answer[i] == guess:
            display[i] = guess
            length=length-1
    print(colored("".join(display),"blue"))
    print('\n')
elif choice=='2':
    for i in range(len(display)):
        display[i]=" - "
    print(colored(''.join(display),'blue'))
    print("\n")


while count<length:
    if ex_it<=12:
        print("Chances left:", 13- ex_it)
        ex_it+=1
        guess=input(colored("Guess a letter: ",'yellow'))
        guess=guess.upper()
        for i in range(len(compiler_answer)):
            if compiler_answer[i]==guess:
                display[i]=guess
                count+=1
        print(colored("".join(display),"blue"))
        print("\n")
    else:
        print(colored("Hi {} you loose the game".format(name),'red'))
        print(colored("Play next time !","red"))
        print(colored("The answer was: {}".format(answer),'green'))
        exit(0)
print(colored("Hi {} you guess the word sucessfully".format(name),'green'))
print(colored("You won the match",'green'))


