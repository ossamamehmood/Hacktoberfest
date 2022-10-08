import re #this stands for import regular expressions
#TASK 8
#validation is very important in programs - it is to ensure that the data entered into your program is VALID - not rubbish!
#In the creation of a password #at least 6 digits (no less)
#at least one number
#at least one character

#TASK: ANALYSE THE WAY THE WHILE LOOP WORKS. Add messages to warn the user
#when they are getting it wrong for uppercase, character, and blank space....

def main():
          password= input("Create a password : ")
          x = True #random variable x which is set to TRUE
          while x:  #while x is TRUE,then run the following which is in the loop
              if (len(password)<6 or len(password)>12): #if password not between 6 and 12 exit loop
                  print("Password length between 6 and 12 please")     
                  break #exit the WHILE LOOP
              elif not re.search("[a-z]",password): #if password doesn't contain one lowercase letter
                  print("You need at least one lower case letter")
                  break
              elif not re.search("[0-9]",password): #if pasword doesn't contain numbers
                  print("You need at least one number")
                  break
              elif not re.search("[A-Z]",password): #if password doesn't contain upper case letter
                  print("You need at least one upper case character")
                  break
              elif not re.search("[$#@]",password): #if password doesn't contain character
                  print("You need at least one special character please")
                  break
              elif re.search("\s",password): #if contains blank space
                  print("You cannot have blank spaces in your password...")
                  break
              else:
                  print("Valid Password")
                  x=False #Valid password has been created, so set x to False and exit the loop
                  break

          if x: #note this is outside the while loop (so the code jumps to it, if BREAK is typed inside the loop
              print("Not a Valid Password")
              main()

main()
