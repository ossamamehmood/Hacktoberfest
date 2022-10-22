# Python program to Count Uppercase, Lowercase, special character and numeric values using Regex

import re
string = "ThisIsRegexTutorial !, 234"

up_characters = re.findall(r"[A-Z]", string)
low_characters = re.findall(r"[a-z]", string)
num_characters = re.findall(r"[0-9]", string)
spl_characters = re.findall(r"[, .!?]", string)

print("The no. of uppercase characters is", len(up_characters))
print("The no. of lowercase characters is", len(low_characters))
print("The no. of numerical characters is", len(num_characters))
print("The no. of special characters is", len(spl_characters))
