# Problem Statement

# There are 100 closed doors. A cage holding 100 monkeys is placed nearby. Every monkey that visits a door either opens a closed door or closes an open door. 
# The first monkey that is let out of the cage visits and opens all the hundred doors. The second monkey that is released visits doors of the order 2, 4, 6, 8, 10…. . 
# The third monkey released visits doors 3, 6, 9,12, 15……, and so on.

# After all the monkeys from the cage are released and have opened or closed at least one door, how many doors are left open?

# Approach

# Prime and composite numbers have an even number of factors, and perfect squares have an odd number of factors. 
# We can infer that prime and composite numbered doors end up being closed, while doors with perfect square numbers remain open. 

# Since there are 10 perfect squares between 1 and 100, there are 10 numbers that have an odd number of factors. Hence, 10 doors will remain open.

n = 100
opendoors = 0
for x in range(1, n+1):
    if x*x <= n:
        opendoors += 1
print(opendoors)    
