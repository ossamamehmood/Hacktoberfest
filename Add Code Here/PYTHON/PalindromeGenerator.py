# Palindrome is a word, phrase, or sequence that reads the same backwards as forwards

#getting the input string
string=input('enter a stirng to get the corresponding palindrome: ')
l=len(string)

print('the generated palindrome is: ',end='')

# if length of the input string is even
if l%2==0:
    print(string,end='')
    for i in range(l):
        print(string[l-1],end='')
        l=l-1

# if length of the input string is odd
else:
    print(string,end='')
    for i in range(l-1):
        print(string[l-2],end='')
        l=l-1