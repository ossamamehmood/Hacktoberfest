def reverseNumber (n: int):
    is_negative = False
    if n < 0:
        is_negative = True
        n = n * -1
    
    temp = n
    result = 0
    while(n > 0):
        dig = n % 10
        result = result * 10 + dig
        n = n // 10
        
    if is_negative:
        result = result * -1
    
    return result
    
print(reverseNumber(123))
print(reverseNumber(-123))
