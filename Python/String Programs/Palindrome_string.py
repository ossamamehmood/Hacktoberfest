# Python Program to Check Whether a String is Palindrome or Not
# Contributed by Abhishek Jaiswal

string=raw_input("Enter string:")
if(string==string[::-1]):
      print("The string is a palindrome")
else:
      print("The string isn't a palindrome")