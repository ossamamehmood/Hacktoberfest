# Following is the implementation of Playfair Cipher Encryption Algorithm in Cryptography
# Inputs required from user: Key and Plaintext, both strings
# Example:

# Enter the key: phoebe
# Enter plain text: friends
# Key Matrix generated is:
# p       h       o       e       b
# a       c       d       f       g
# i       k       l       m       n
# q       r       s       t       u
# v       w       x       y       z
# Cipher text: ctmplgux

keyT = [[0] * 5 for i in range(5)]

# Convert (break) a string into individual letters in a list
def Convert(string):
    list1 = []
    list1[:0] = string
    return list1


# Convert all input string characters into lowercase
def ToLowerCase(plain, ps):
    for i in range(ps):
        if ord(plain[i]) > 64 and ord(plain[i]) < 91:
            plain[i] = chr(ord(plain[i]) + 32)


# Remove spaces if any in the input string
def RemoveSpaces(plain, ps):
    count = 0
    for i in range(ps):
        if plain[i] != " ":
            plain[count] = plain[i]
            count = count + 1
    return count


# Given a key, generate the Key Table
def GenerateKeyTable(key, ks):
    chars = [0] * 26
    for i in range(len(key)):
        if key[i] != "j":
            chars[ord(key[i]) - 97] = 2
    chars[ord("j") - 97] = 1

    i = 0
    j = 0
    for k in range(len(key)):
        if chars[ord(key[k]) - 97] == 2:
            chars[ord(key[k]) - 97] -= 1
            keyT[i][j] = key[k]
            j += 1
            if j == 5:
                i += 1
                j = 0
    for k in range(26):
        if chars[k] == 0:
            keyT[i][j] = chr(k + 97)
            j += 1
            if j == 5:
                i += 1
                j = 0

    print("Key Matrix generated is:")
    for i in range(5):
        for j in range(5):
            print(keyT[i][j], end="\t")
        print()


# Function to search 2 characters at a time in the Key Table and return the positions in an array
def Search(a, b, arr):

    if a == "j":
        a = "i"
    elif b == "j":
        b = "i"

    for i in range(5):
        for j in range(5):
            if keyT[i][j] == a:
                arr[0] = i
                arr[1] = j
            elif keyT[i][j] == b:
                arr[2] = i
                arr[3] = j


def Mod5(a):
    return a % 5


# Adding 'z' at the end if odd number of characters
def Prepare(stri, ptrs):
    if ptrs % 2 != 0:
        stri.append("z")
        ptrs = ptrs + 1
    return ptrs


# Generating the encrypted characters for each plaintext character
def Encrypt(str, ps):
    a = [0] * 4
    i = 0
    for i in range(0, ps, 2):
        Search(str[i], str[i + 1], a)
        if a[0] == a[2]:
            str[i] = keyT[a[0]][Mod5(a[1] + 1)]
            str[i + 1] = keyT[a[0]][Mod5(a[3] + 1)]
        elif a[1] == a[3]:
            str[i] = keyT[Mod5(a[0] + 1)][a[1]]
            str[i + 1] = keyT[Mod5(a[2] + 1)][a[1]]
        else:
            str[i] = keyT[a[0]][a[3]]
            str[i + 1] = keyT[a[2]][a[1]]


# Encryption function for Playfair Cipher
def EncryptByPlayfairCipher(stri, key):
    ks = len(key)
    ks = RemoveSpaces(key, ks)
    ToLowerCase(key, ks)

    ps = len(stri)
    ToLowerCase(stri, ks)
    ps = RemoveSpaces(stri, ps)
    ps = Prepare(stri, ps)
    GenerateKeyTable(key, ks)
    Encrypt(stri, ps)


key1 = input("Enter the key: ")
key = Convert(key1)
stri1 = input("Enter plain text: ")
stri = Convert(stri1)

EncryptByPlayfairCipher(stri, key)
print("Cipher text:", "".join(stri))
