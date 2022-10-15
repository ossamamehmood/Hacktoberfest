from encodings import utf_8

print("███████████████████████████████████████████████")
print("█▄─▄─▀█▄─▄█▄─▀█▄─▄█─▄▄▄▄█▄─█▀▀▀█─▄██▀▄─██▄─▄▄─█")
print("██─▄─▀██─███─█▄▀─██▄▄▄▄─██─█─█─█─███─▀─███─▄▄▄█")
print("▀▄▄▄▄▀▀▄▄▄▀▄▄▄▀▀▄▄▀▄▄▄▄▄▀▀▄▄▄▀▄▄▄▀▀▄▄▀▄▄▀▄▄▄▀▀▀")
print()
choice = input("Encode(e) or Decode(d): ")
print()
def encode():

    def toBinary(string):
        binary = ''
        for character in string:
            binary = binary + bin(ord(character))[2:].zfill(8) + ' '
        return binary.strip()

    #Geting a string to encode
    user_string = input("Enter a string to encode: ")
    print()

    #Converting the string to binary
    bin_encoded = (toBinary(user_string))

    #Reversing the converted binary
    txt = bin_encoded[::-1] 

    #Encoding to hex
    str = txt.encode('utf-8')
    hex = str.hex()

    print("Encoded Text- " + hex)
    print()

def decode():
    #Getting a string to decode
    user_input = input("Enter a string to decode: ")
    print()

    #Decoding string as hex
    hex_decoded = bytes.fromhex(user_input).decode('utf-8')
    
    #Unreversing string
    unreversed_string = hex_decoded[::-1]

    #Converting binary string to text 
    binary_string = unreversed_string
    ascii_string = "".join([chr(int(binary, 2)) for binary in binary_string.split(" ")])

    print("Decoded String: " + ascii_string)
    print()

if choice=="encode":
    encode()
elif choice=="decode":
    decode()
elif choice=="e":
    encode()
elif choice=="d":
    decode()
else:
    print("Incorrect Option, Please check again")


