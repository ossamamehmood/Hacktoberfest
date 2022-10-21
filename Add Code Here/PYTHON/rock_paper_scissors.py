#program for rock paper scissors

import random
import time


def game():
    print("\tWELCOME\t")
    print("the game is starting")
    
    time.sleep(0.7)
    
    print("\nrules:\n")
    print("this is a game between the computer and you\n")
    print("for rock press 'r'\nfor paper type 'p'\nfor scissors type 's'")
    print("dont press any key(s) until next message ")
    time.sleep(5)
    print("\nlets begin\n")
    time.sleep(0.2)
    game=['r','p','s']
    print("how many rounds do you want to play? ")
    print("remember you cant leave before the match is over ! ")
    rd=int(input(':'))
    
    countu=0
    countc=0
    if rd==0:
        print("OK...! :)")
        exit 
    else :
        print("\nlets begin\n")
        time.sleep(0.2)
        print("\tthe score right now :\t")
        print('\tuser : ',countu)
        print('\tcomputer',countc)
        for i in range(rd):
            comp=random.choice(game)
            inu=input('\nenter your choice:\n')    
            print('\nuser entered : ',inu)
            print('\ncomputer entered : ',comp)
        
            if inu == comp:
                print("No points aadded or deducted")
                pass
            elif inu.lower()=='s' and comp=='p'or inu.lower()=='r' and comp=='s' or inu.lower()=='p' and comp=='r':
                print('\n\t+1 for user :) ')
                countu=countu+1
            elif comp=='s' and inu.lower()=='p'or comp=='r' and inu.lower()=='s'or comp=='p' and inu.lower()=='r':
                print('\n\t+1 for computer :) ')
                countc=countc+1
            else :
                print("\t\terror! choose from menu(r,p,s) only ")
                print("\t\twrong value entered")
                print("\t\t1 point deducted from user")
                countu=countu-1
            
            print("\tthe final score now :\t")
            time.sleep(0.2)
            print('\tuser : ',countu)
            print('\tcomputer',countc)
        
        if countu>countc:
            print("\tuser WON!!\n")
        elif countu<countc:
            print("\tcomputer WON!!\n")
        else:
            print("\tits a tie :\n\n")
            time.sleep(0.1)
        print("play again?\n")
        again()
        
def again():
    ans=input('y/n:')
    if ans.lower() == 'y':
        game()
    elif ans.lower() == 'n':
        print( "ok     \n \n \n:)")
    else :
        print("ok let it be ...........    :_)")
        

#__main__
        
print('wanna play rock paper scissors ?  \n')
again()

