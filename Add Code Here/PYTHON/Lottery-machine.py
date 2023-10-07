import random
import time

MAX_LINES=3
MIN_BET =1
MAX_BET=1000

ROWS=3
COLS=3

RED = "\033[38;2;255;0;0m"
GREEN = "\033[38;2;0;255;0m"
BLUE = "\033[38;2;0;0;255m"
RESET = "\033[0m"

symbol_count={
    "🤡":10,
    "🚀":2,
    "🐍":10,
    "👀":2,
    "🏀":1,
    "💊":2,
    "💡":3,
    "🌈":3,
    "🔥":2,
    "💧":1,
    "⚡":2,
    "❤️":10,
    "💔":10,
    "☢️":2,
    "*️⃣":1
    
}

symbol_values={
    "🤡":6,
    "🚀":2,
    "🐍":10,
    "👀":3,
    "🏀":15,
    "💊":2,
    "💡":2,
    "🌈":9,
    "🔥":5,
    "💧":15,
    "⚡":2,
    "❤️":5,
    "💔":10,
    "☢️":3,
    "*️⃣":15
    
}





def check_win(columns,lines,bet,values):
    winnings=0
    winning_lines=[]
    for line in range(lines):
        symbol=columns[0][line]
        for column in columns:
            symbol_to_check=column[line]
            if symbol!=symbol_to_check:
                break
        else:
            winnings+=values[symbol]*bet
            winning_lines.append(line+1)
    return winnings,winning_lines

            
    


def get_spin(rows,cols,symbols):
    all_symbols=[]
    for symbol, symbol_count in symbols.items():
        for _ in range(symbol_count):
            all_symbols.append(symbol)
            
    columns = []
    for col in range(cols):
        column = []
        current_symbols=all_symbols[:] #we use [:] since we want to pass a copy and not the reference
        for row in range(rows):
            value=random.choice(current_symbols)
            current_symbols.remove(value)
            column.append(value)
            
        columns.append(column)
        
        
    return columns





def print_spin(columns):
    for row in range(len(columns[0])):
        for i,column in enumerate(columns):
            if i!=len(columns)-1:
                print(column[row],end=' | ')
            else:
                print(column[row],end='')
        print()
                



def deposit():
    while True:
        amount=input("Enter the amount you would like to deposit: 💲")
        if(amount.isdigit()):
            amount=int(amount)
            if (amount>0):
                break
            else:
                print("Amount must be greater than 0.\n")
        else:
            print("Please enter a valid amount.\n")
    return amount
           



def get_num_of_lines():
    while True:
        lines=input("Enter the number of lines to bet on (1-" + str(MAX_LINES)+") : ")
        if(lines.isdigit()):
            lines=int(lines)
            if (1<=lines<=MAX_LINES):
                break
            else:
                print("Enter a valid number of lines.\n")
        else:
            print("Please enter a number.\n")
    return lines           
  
  
  
  
def get_bet():
    while True:
        amount=input("Enter the amount to bet on each line: 💲")
        print()
        if(amount.isdigit()):
            amount=int(amount)
            if (MIN_BET<=amount<=MAX_BET):
                break
            else:
                print(f"Amount must be between 💲{MIN_BET} - 💲{MAX_BET}.\n")
        else:
            print("Please enter a number.\n")
    return amount       




def add_money(balance):
    choice=input("Do you want to add more money? (y/n): ")
    print()
    if choice=="y":
        while True: 
            amt=(input("Enter the amount to add: 💲"))
            if amt.isdigit():
                amt=int(amt)
                if (amt>0):
                    balance+=amt
                    break
                else:
                    print("Amount must be greater than 0.\n")
            else:
                print("Please enter a valid amount.\n")
    print(f"Current Balance: 💲{balance}")
    print()
    return balance





def spin(balance):
    while True:
        lines=get_num_of_lines()
        bet=get_bet()
        if((bet*lines)>balance):
            print("You don't have enough balance to bet that amount.")
            balance = add_money(balance)
            
        else:
            break
    print(f"You are betting 💲{bet} on {lines} lines")
    print(f"Total betting amount = 💲{bet*lines}")
    print()
    print("The Lottery Machine is Rolling...")
    print()
    time.sleep(1)
    print("Almost There!!")
    time.sleep(0.75)
    print("Here comes the result!")
    print()
    time.sleep(0.5)

    slots=get_spin(ROWS,COLS,symbol_count)
    print_spin(slots)

    winnings,winning_lines=check_win(slots,lines,bet,symbol_values)

    if(winnings>0):
        print()
        print(f"Congratulations! You have won 💲{winnings}")
        print(f"You won on lines: ",*winning_lines)
        print()
    else:
        print()
        print("You didn't win anything.")
        print("Better Luck next time!")
        print()
    return balance + winnings-(bet*lines)




def main():
    
    
    print(RED +'''
 _          _   _                    __  __            _     _            _ 
| |    ___ | |_| |_ ___ _ __ _   _  |  \/  | __ _  ___| |__ (_)_ __   ___| |
| |   / _ \| __| __/ _ \ '__| | | | | |\/| |/ _` |/ __| '_ \| | '_ \ / _ \ |
| |__| (_) | |_| ||  __/ |  | |_| | | |  | | (_| | (__| | | | | | | |  __/_|
|_____\___/ \__|\__\___|_|   \__, | |_|  |_|\__,_|\___|_| |_|_|_| |_|\___(_)
                             |___/
         ''')
    print(GREEN + " By : Ash-codes18")
    print()
    print()
    print(BLUE+"Welcome to the Lottery Machine!"+ RESET)
    print()
    print()
    
    
    balance =deposit()
    while True:
        print(f"Current Balance : 💲{balance}")
        print()
        choice=input("Press enter to play (q to quit).")
        print()
        
        if choice.lower()=="q":
            print()
            print("Thank You for Using the Lottery Machine!")
            print("Exiting...")
            time.sleep(1)
            break
        else:
            balance = spin(balance)
    print()   
    
        
main()