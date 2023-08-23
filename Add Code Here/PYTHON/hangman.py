# Author : Jatin Jindal
# Collaborators : None
# Problem Statement : Calculate sum or all fibonacchi numbers less than 4,000,000

def fibonachi(fib_dict, n):
    '''
    Input -> 
    fib_dict : dictionary which maps a number to fibonacchi number
    at the index equal to that number.
    n : The index we want the fibonacchi number for
    
    Output -> Returns the dicitonary with all sequence values up to 'n'.
    '''
    if n in fib_dict:
        return fib_dict[n]
    else:
        ans = fibonachi(fib_dict, (n - 1)) + fibonachi(fib_dict, (n - 2))
        fib_dict[n] = ans
        return ans
    
def calculate_sum(fib_dict, upper=4000000):
    '''
    Input -> 
    fib_dict : dictionary which maps a number to fibonacchi number
    at the index equal to that number.
    upper : the upper number till which we want the sum
    
    Output -> Returns the sum of all sequence values up to <= upper.
    '''
    sum = 0
    i = 2
    while fibonachi(fib_dict, i) < upper:
        if fibonachi(fib_dict, i) % 2 == 0:
            sum += fibonachi(fib_dict, i)
        i += 1
    return sum
    
fib_dict = {1:1, 2:2}
print(calculate_sum(fib_dict))