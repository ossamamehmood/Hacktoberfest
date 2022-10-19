from cryptography.fernet import Fernet

master_pwd = "Viveena@30" 
password = input("enter master password")
'''
def write_key():
    key = Fernet.generate_key()
    with open("key.key", "wb") as key_file:
        key_file.write(key)'''

def load_key():
    file = open("key.key", "rb")
    key = file.read()
    file.close()    
    return key 

# write_key()

key = load_key()
fer = Fernet(key) 


def view():
    with open('password.txt', 'r') as f:
        for line in f.readlines():
            data = line.rstrip()
            user, passw = data.split (" | ")
            print("User :" , user , "Password :", fer.decrypt(passw.encode()).decode())

def add():
    name = input("Account Name : ")
    pwd = input("Password : ")
    with open('password.txt', 'a') as f:
        f.write(name + " | " + fer.encrypt(pwd.encode()).decode() + "\n")
        pass


if password == master_pwd:
    while True:
        mode = input("add or view? (a , v) and (q) to quit : ").lower()

        if mode == 'q':
            break

        if mode == 'v':
            view()
        elif mode == 'a':
            add()
        else:
            print("invalid mode. ")
            continue