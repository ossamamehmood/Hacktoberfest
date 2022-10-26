# GUESS THE TRIANGLE
#By: Darwin Jimenez

def triangle(a, b, c):
    if a == b and b == c:
        print("equilateral triangle")
    elif a == b and b != c: 
        print("isosceles triangle")
    else:
        print("scalene triangle")
        
triangle(4,4,5)