def ispal (s):
 for i in range(len(s)):
  if s[i] != s[len(s)-1-i]:
    return False
  return True
s=input("Enter a string value: ")
print(s, "is", "\b" if ispal(s) else "not", "palindrome.")
