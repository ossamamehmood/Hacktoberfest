"""
Shift Cipher:
    Using this program first we have to input 0 or 1 to decipher or cipher the text.
    Then input the text which need to processed and press Enter.
    Now input your key and press Enter. We will get output as result whatever we have given input altogether.
"""

alpha = "abcdefghijklmnopqrstuvwxyz"
Calpha = alpha.upper()
task = int(input("Enter 0 for decipher or 1 for cipher the text: "))
txt = input("Enter text: ")
key = int(input("Enter your key: "))

res = []
for i in txt:
    if task:
        if i.isupper():
            res.append(Calpha[(Calpha.index(i)+key)%26])
        else:
            res.append(alpha[(alpha.index(i)+key) % 26])
    else:
        if i.isupper():
            res.append(Calpha[(Calpha.index(i)-key)%26])
        else:
            res.append(alpha[(alpha.index(i)-key) % 26])
print("".join(res))
