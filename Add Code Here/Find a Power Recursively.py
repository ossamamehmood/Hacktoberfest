#Find a Power Recursively

def find_power(a, b):
    if b == 0:
        return 1
    else:
        return a * find_power(a, b-1)