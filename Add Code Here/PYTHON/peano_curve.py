#create a string s as URDRU.
s = 'URDRU'
#define a new function named one to get the first version of s.
def one(s):
        r=''
        #using for loop to iterate i till the length of s.
        for i in range(len(s)):
            #create an empty string r.
            
            #using if-else statement to define the new directions of base accordingly.
            if s[i] == 'U':
                r+='U'
            elif s[i] == 'R':
                r+='L'
            elif s[i] == 'D':
                r+='D'
            elif s[i] == 'R':
                r+='L'
            elif s[i] == 'U':
                R+='U'
             
        return r

    #define a new function clock() to get the clockwise version of base.

#define a new function named two to get the second version of s.
def two(s):
        r=''
        #using for loop to iterate i till the length of s.
        for i in range(len(s)):
            #create an empty string r.

            #using if-else statement to define the new directions of base accordingly.
            if s[i] == 'U':
                r+='D'
            elif s[i] == 'R':
                r+='R'
            elif s[i] == 'D':
                r+='U'
            elif s[i] == 'R':
                r+='R'
            elif s[i] == 'U':
                R+='D'

        return r

#define a new function named three to get the third version of s.
def three(s):
        r=''
        #using for loop to iterate i till the length of s.
        for i in range(len(s)):
            #create an empty string r.

            #using if-else statement to define the new directions of base accordingly.
            if s[i] == 'U':
                r+='D'
            elif s[i] == 'R':
                r+='L'
            elif s[i] == 'D':
                r+='U'
            elif s[i] == 'R':
                r+='L'
            elif s[i] == 'U':
                R+='D'

        return r

#define a function named final to get the final pattern given in the problem.
def final(n):
#using if else statements to define the function at 1 and using recursion for subsequent values.
        if n == 1:
             return 'URDRU'
       
        else:
             g= final(n-1)+'U'+one(final(n-1))+'U'+final(n-1)+'R'+two(final(n-1))+'D'+three(final(n-1))+'D'+two(final(n-1))+'R'+final(n-1)+'U'+one(final(n-1))                +'U'+final(n-1)
        return g 

    #now finally define a new function coor which will convert the above final string into coordinates as tuples.
def coor(s):
        #create an empty list l.
        l = [(1,1)]
        
        #define two variables x and y as both 1 to represent (1,1).
        x = 1
        y = 1

        #using if else statement to define the new coordinates of x and y.
        for i in range(len(s)):
            if s[i] == 'D':
                x +=1

            elif s[i] == 'U':
                x -=1

            elif s[i] == 'L':
                y -=1

            elif s[i] == 'R':
                y +=1
            
            l.append((x,y))
        return l

#take input of a number from the user.
n = int(input("enter a number: "))
print(coor(final(n)))
print(len(coor(final(n))))
