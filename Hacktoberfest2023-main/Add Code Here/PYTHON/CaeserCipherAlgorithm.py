'''
The encryption step performed by a Caesar cipher is often incorporated as part of more complex schemes, such as the Vigenère cipher, and still has modern application in the ROT13 system. As with all single-alphabet substitution ciphers, the Caesar cipher is easily broken and in modern practice offers essentially no communications security.

The action of a Caesar cipher is to replace each plaintext letter with a different one a fixed number of places down the alphabet.

The encryption can also be represented using modular arithmetic by first transforming the letters into numbers, according to the scheme, A → 0, B → 1, ..., Z → 25.[2] Encryption of a letter x by a shift n can be described mathematically as,

Encryption(x) = (x + n)%26
Decryption(x) = (x - n)%26
'''

'''
Algorithm for Caesar Cipher: 

Input: A String of lower case letters, called Text and an Integer between 0-25 denoting the required shift.

Procedure: 
1. Traverse the string characters.
2. For each character, transform the given character as per the rule, depending on whether we’re encrypting or decrypting the text.
3. Return the new string generated.

To decrypt remember Cipher(n) = De-cipher(26-n)
'''

def encrypt(plain_text, n):
    result = ""

    for i in range(len(plain_text)):
        char = plain_text[i]
 
        # Encrypt uppercase characters
        if (char.isupper()):
            result += chr((ord(char) + n-65) % 26 + 65)
 
        # Encrypt lowercase characters
        else:
            result += chr((ord(char) + n - 97) % 26 + 97)
 
    return result

def decrypt(encrypted_string, n):
    result = ""
    n = 26 - n

    for i in range(len(encrypted_string)):
        char = encrypted_string[i]
 
        # Encrypt uppercase characters
        if (char.isupper()):
            result += chr((ord(char) + n-65) % 26 + 65)
 
        # Encrypt lowercase characters
        else:
            result += chr((ord(char) + n - 97) % 26 + 97)
 
    return result

plain_text = "TestThisString"
n = 4
print("Text  : ", plain_text)
print("Shift : ", str(n))
encrypted_string = encrypt(plain_text, n)
print("Cipher: ", encrypt(plain_text, n))
print("Decrypted Cipher Text: ", decrypt(encrypted_string, n))