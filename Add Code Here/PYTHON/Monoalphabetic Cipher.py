"""
Monoalphabetic Cipher Code:
    Using this program we can encrypt or decrypt our text with custom key.
    To encrypt enter 1 and to decrypt enter 0, then enter the text you have.
    After that input the key you have and press Enter.
    You will get necessary output as per your choices.
"""

plain = "abcdefghijklmnopqrstuvwxyz"
Cplain = plain.upper()
task = input("Enter 0 for cipher input or 1 for plain input: ")
txt = input("Enter the text: ")
key = input("Enter the key: ")
Ckey = key.upper()

res = []
for i in txt:
    if i.isupper():
        if int(task):
            res.append(Ckey[Cplain.index(i)])
        else:
            res.append(Cplain[Ckey.index(i)])
    else:
        if int(task):
            res.append(key[plain.index(i)])
        else:
            res.append(plain[key.index(i)])
print("".join(res))
