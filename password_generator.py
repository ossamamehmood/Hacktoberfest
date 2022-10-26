import string  #importing string module for alphabets and digits
import random  #importing random to create random password

#to access lowercase alphabets
s1= string.ascii_lowercase
#to access uppercase alphabets
s2=string.ascii_uppercase
#to access digits
s3=string.digits
#to access punctuation marks
s4=string.punctuation

#creating empty list to change strings into characters
p=[]
#adding s1 to empty list
p.extend(list(s1))
#adding s2 after s1
p.extend(list(s2))
#adding s3 after s2
p.extend(list(s3))
#adding s4 after s3
p.extend(list(s4))

#taking input from user about  length of password
plen=int(input("Enter Password Length: "))
#taking input from user about where to store password
psite=input("Enter Site name where you will use password: ")

#using random.shuffle to generate letters and digits
random.shuffle(p)
#joining random letters and digits upto length entered by user in empty string 
password=("".join(p[0:plen]))
#comment line for user
print("Your password is :")
#printing output
print(password)
