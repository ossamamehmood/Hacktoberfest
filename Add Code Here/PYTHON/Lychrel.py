""" Code to solve Lychrel number
    So this is a very popular math question
    The idea is to take any number as num and reverse it.
    Now add the reversed number to num and repeat the process unless
    a palindrome is obtained. The weird thing about this process is that
    for nearly every number ends with a palindrome except the number 196 
    noone is able to explain why:)"""
"""
DO NOT REMOVE THIS COMMENT AS THE CODE BELOW INCREASE THE RECUSION LIMIT
THIS MAY ALSO RESULT TO TOTAL CRASH OF THE SYSTEM. IF YOUR PC IS STRONG ENOUGH TO TACKLE
RECURSION, FEEL FREE TO USE THE CODE BY REMOVING THE COMMENTS.

#import sys
#sys.setrecursionlimit(1500)
"""
#function to solve the lychrel number
def prob(num):
        temp=num
        rev=0
        while(num>0):
            dig=num%10
            rev=rev*10+dig
            num=num//10
        if(temp==rev):
            print(f"At last! we found a palindrome which is {temp}")
        else:
            print(f"The number {temp} isn't a palindrome!")
            again = temp + reverse(temp)
            prob(again)


#function to reverse a given number
def reverse(num):
    reversed_num = 0

    while num != 0:
        digit = num % 10
        reversed_num = reversed_num * 10 + digit
        num //= 10

    return reversed_num


#driver code
num = int(input("Enter a two digit number or more"))
prob(num)

