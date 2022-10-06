def test(lst):
    result = sorted(lst, key=lambda x: not x) 
    return result
  
nums = [3,4,0,0,0,6,2,0,6,7,6,0,0,0,9,10,7,4,4,5,3,0,0,2,9,7,1]
print("\nOriginal list:")
print(nums)
print("\nMove all zero digits to end of the said list of numbers:")
print(test(nums)) 
