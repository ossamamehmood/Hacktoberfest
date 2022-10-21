#Maximum Consecutive Substring Occurrence
#Contributed by Abhishek Jaiswal

import re
test_str = raw_input("Enter string:")
print("The original string is : " + str(test_str))
sub_str = raw_input("Enter substring:")
res = max(re.findall('((?:' + re.escape(sub_str) + ')*)', test_str), key = len)
print("The maximum run of Substring : " + res)