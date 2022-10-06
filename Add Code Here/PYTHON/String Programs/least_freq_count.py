# Least Frequent Character in String
# Contributed by Abhishek Jaiswal

from collections import Counter
test_str = raw_input("Enter string:")
print ("The original string is : " + test_str)
res = Counter(test_str)
res = min(res, key = res.get)
print ("The minimum of all characters is : " + str(res))
