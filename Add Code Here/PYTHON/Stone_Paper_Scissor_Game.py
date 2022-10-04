import random

print("""
          ______      ______       ______ 
         /  ___/     |  __  \     /  ___/
        |  (__       | |__)  |   |  (__   
         \__  \      |   ___/     \__  \  
         ___)  | _   |  |    _    ___)  | _
        /_____/ |_|  |__|   |_|  /_____/ |_| 
""")

print("""
         Welcome to Stone Paper Scissor!
""")

print("""
\n\t\t Instructions: \n\tThere will be 10 Matches to be played.
""")


winner = ""


def Game():
    userScore, compScore = 0, 0
    a = 1
    while a <= 10:
        print("""
________________________________________________________
      """)
        print(f"\n \t\tMatch : {a}\n")
        user = input("Enter either 'Stone / Paper / Scissor' : ")
        computer = random.randint(1, 100)
        comp = ""

        if computer <= 33:
            comp = "Stone"
        if computer > 33 and computer <= 66:
            comp = "Paper"
        if computer > 66 and computer <= 100:
            comp = "Scissor"

        print(f"""
      Computer's choice :{comp}
      User's choice :{user}
      """)

        # Computer
        if comp == "Stone" and (user == "Scissor" or user == "scissor"):
            compScore = compScore+1

        if comp == "Paper" and (user == "Stone" or user == "stone"):
            compScore = compScore+1

        if comp == "Scissor" and (user == "Paper" or user == "paper"):
            compScore = compScore+1

        # User
        if (user == "Stone" or user == "stone") and comp == "Scissor":
            userScore = userScore+1

        if (user == "Paper" or user == "paper") and comp == "Stone":
            userScore = userScore+1

        if (user == "Scissor" or user == "scissor") and comp == "Paper":
            userScore = userScore+1

        # same

        if comp == "Stone" and user == "Stone" or user == "stone":
            userScore, compScore = userScore, compScore

        if comp == "Paper" and user == "Paper" or user == "paper":
            userScore, compScore = userScore, compScore

        if comp == "Scissor" and user == "Scissor":
            userScore, compScore == userScore, compScore

        print(f"""
      User Score : {userScore}
      Computer : {compScore}
            """)
        if compScore < userScore:
            winner = "User"
            print(f"\tLead : {winner}\n")

        if userScore < compScore:
            winner = "Computer"
            print(f"\tLead : {winner}\n")

        if compScore == userScore:
            winner = "Both"
            print(f"\tLead : {winner}\n")

        if a == 10:
            print(f"\n\t\nGame won by : {winner}\n")
        a = a+1


Game()
