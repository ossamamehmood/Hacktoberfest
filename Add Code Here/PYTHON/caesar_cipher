def encrypt_function(ptxt,key):
    ctxt=""
    for i in range(len(ptxt)):
        char =ptxt[i]
        if(char.isupper()):
            ctxt+=chr((ord(char)+key-65)%26+65)
        else:
            ctxt+=chr((ord(char)+key-97)%26+97)
    return ctxt

def decrypt_function(ctxt,key):
    ptxt=""
    for i in range(len(ctxt)):
        char =ctxt[i]
        if(char.isupper()):
            ptxt+=chr((ord(char)-key-65)%26+65)
        else:
            ptxt+=chr((ord(char)-key-97)%26+97)
    return ptxt

def main():
    print("_-_-_-_-_-_-_-_-_ Caesar Cipher _-_-_-_-_-_-_-_-_")
    ch="Y"
    key=3
    while(ch=="Y" or ch=="y"):
        print("\n\t*** MENU ***")
        print("\n1. Caeser Cipher {Key is fixed}.")
        print("2. Shift Cipher {Key is entered}.\n")
        ans1=int(input("\tEnter your choice: "))
        
        print("\n1. Encyrption")
        print("2. Decryption\n")
        ans2=int(input("\tEnter your choice: "))
        
        if(ans1==1 and ans2==1):
            input_txt=input("\nEnter plain text: ")
            print("\nPLAIN TEXT:",input_txt)
            print("CIPHER TEXT:",encrypt_function(input_txt,key))
        elif(ans1==1 and ans2==2):
            input_txt=input("\nEnter cipher text: ")
            print("\nCIPHER TEXT:",input_txt)
            print("PLAIN TEXT:",decrypt_function(input_txt,key))
        elif(ans1==2 and ans2==1):
            key=int(input("\nEnter the key: "))%26
            
            input_txt=input("Enter plain text: ")
            print("\nPLAIN TEXT:",input_txt)
            print("CIPHER TEXT:",encrypt_function(input_txt,key))
        elif(ans1==2 and ans2==2):
            key=int(input("\nEnter the key: "))%26
            
            input_txt=input("Enter cipher text: ")
            print("\nCIPHER TEXT:",input_txt)
            print("PLAIN TEXT:",decrypt_function(input_txt,key))
        else:
            print("\nInvalid option! Try again")
        
        ch=input("\nDo you want to try again? {Y/N}: ")
        print("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*")

main()
