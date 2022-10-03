#The reverse alphabet pyramid pattern is a pyramid pattern that is made of alphabets and is upside down.
#For Example:
#ABCDEFGHI
# ABCDEFG
 # ABCDE
  # ABC
  #  A

  #Sourcecode
  # reverse alphabet pyramid pattern
size = int(input("Enter The levels upto which you want to create a reverse pyramid pattern of alphabets"))
alpha = 65

for i in range(size):
    # print spaces
    for j in range(i):
        print(" ", end="")
    # print alphabets
    for k in range(2 * (size - i) - 1):
        print(chr(alpha + k), end="")
    print()
