import random
def choose():
    words = ['Anshuman', 'Jasmine','Lily','Crow','monk','monkey','goose','Activity','stranger','invoke']
    word = random.choice(words)
    return(word)
def jumble(word):
    jumbled = "".join(random.sample(word,len(word)))
    return(jumbled)
def thank(p1n,p2n,p1,p2):
    print(p1n,'YOur score is:',p1)
    print(p1n,'YOur score is:',p2)
    if p1>p2:
        print(p1n,"won the game")
    elif(p1==p2):
        print("Game drawn")
    else:
        pirnt(p2n,"won the game")
    print("thanks for playing\n Have a nice day")
p1n = input("Enter name of player1")
p2n = input("Enter name of player2")
p1 = 0
p2 = 0
turn = 0
while(1):
    picked_word = choose()
    qn = jumble(picked_word)
    print(qn)
    if(turn%2==0):
        print(p1n,"It's your turn")
        n = input("Enter the word in my mind")
        if n==picked_word:
            print("You get it right")
            p1 = p1+1
        else:
            print("oops, It was wrong I thought of",picked_word)
        c = int(input("Press 1 to play more and 0 to stop"))
        if c==0:
            print("Thank you for playing")
            print("Your score:")
            thank(p1n,p2n,p1,p2)
            break
    else:
        print(p2n,"It's your turn")
        n = input("Enter the word in my mind")
        if n==picked_word:
            print("You get it right")
            p2 = p2+1
        else:
            
            print("oops, It was wrong I thought of",picked_word)
        c = int(input("Press 1 to play more and 0 to stop"))
        if c==0:
            print("Thank you for playing")
            print("Your score:")
            thank(p1n,p2n,p1,p2)
            break
    turn +=1        
