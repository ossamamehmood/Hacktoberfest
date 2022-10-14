import random
guess_list = [
'samuel',
'activity',
'banana',
'school',
'python',
'programming',
'hangman',
] 

print('WELCOME TO MY HANGMAN GAME\n')
cc = random.choice(guess_list).upper()
guesses = len(cc)+4
repw = ['_' for i in range(len(cc))]
while guesses > 0:
    print(f'WORD: {" ".join(repw)}')
    ug = input('Guess a letter:').upper()
    for char in range(len(cc)):
        if ug==cc[char]:
            repw[char]=ug
    if repw.count('_')==0:
        print(f'WORD: {" ".join(repw)}')
        break
    print('Tries remain:',guesses-1,'\n')
    guesses-=1

        
print('\nYou WIN🎉\n') if repw.count('_')==0 else print('\nYou LOSE💔')