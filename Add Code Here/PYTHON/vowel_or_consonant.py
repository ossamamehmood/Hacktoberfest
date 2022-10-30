letter = input("Type a letter\n")
vogals = {"a", "e", "i", "o", "u"}

if letter in vogals:
    print("Letter is vowel")
else:
    print("Letter is consonant")