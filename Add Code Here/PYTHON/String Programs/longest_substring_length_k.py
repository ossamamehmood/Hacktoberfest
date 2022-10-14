#Longest Substring length of K
# Contributed by Abhishek Jaiswal

import re
test_str = raw_input("Enter string:")
print("The original string is : " + str(test_str))
K = raw_input("Enter length K:")
res = re.findall(r'' + K + '+', test_str)
res = len(max(res, key = len))
print("The Longest Substring Length : " + str(res))