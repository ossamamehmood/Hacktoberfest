import numpy as np
from os import system as bas

moder = int(95)

def conv_ascii(elm):
    if type(elm) == int:
        return chr(elm+32)
    elif type(elm) == str:
        return ord(elm)-32
    else:
        print("Wierd data type found: ", type(elm))
        bas("pause")

def Key_Generator():
    key_str = "smokejack"
    return np.array([conv_ascii(s) for s in key_str]).reshape(3,3)

Key = Key_Generator()


def does_inverse_exist():
    det_key = int(np.linalg.det(Key))%moder
    try:
        inv_mod = pow(det_key, -1, moder)
        # print("Det: ",det_key)
        # print("inv_mod: ",pow(det_key, -1, moder))
    except:
        # print("Det: ",det_key)
        # print("inv_mod: ",pow(det_key, -1, moder))
        return False
    return True


def verify_key_inv(key_inv): #Verify if the result is identity matrix. Then good to go!
    if np.array_equal((Key@key_inv)%moder,np.identity(3)):
        return True
    else:
        return False


def vecls_to_str(ls): #coverts column vetor list into string text
    str_txt = ""
    for v, c in enumerate(ls, 0):
        for it in range(0,3):
            str_txt += conv_ascii(int(ls[v][it]))
    return str_txt

def vlu_ls_to_str(ls): #coverts 1d array of ascii values into string text
    str_txt = ""
    for v in ls:
        str_txt += conv_ascii(int(v))
    return str_txt


def adjointer(matrix):
    mtrx = matrix.ravel()  #ravel() converts 2d array to 1d
    A= +((mtrx[4]*mtrx[8])-(mtrx[5]*mtrx[7]))
    B= -((mtrx[3]*mtrx[8])-(mtrx[5]*mtrx[6]))
    C= +((mtrx[3]*mtrx[7])-(mtrx[6]*mtrx[4]))
    D= -((mtrx[1]*mtrx[8])-(mtrx[2]*mtrx[7]))
    E= +((mtrx[0]*mtrx[8])-(mtrx[2]*mtrx[6]))
    F= -((mtrx[0]*mtrx[7])-(mtrx[1]*mtrx[6]))
    G= +((mtrx[1]*mtrx[5])-(mtrx[2]*mtrx[4]))
    H= -((mtrx[0]*mtrx[5])-(mtrx[2]*mtrx[3]))
    I= +((mtrx[0]*mtrx[4])-(mtrx[1]*mtrx[3]))
    cofactor = np.array([[A, B, C], 
                         [D, E, F], 
                         [G, H, I]])
    adjnt = cofactor.T
    return adjnt #convert back to 2d array + transpose


    
def Key_Inverse():
    det_key = int(np.linalg.det(Key))%moder
    det_inv_mod = pow(det_key, -1, moder)
    adj_key = adjointer(Key)%moder
    key_inv = (det_inv_mod*adj_key)%moder
    return key_inv


def is_key_valid():
    mod_inv = does_inverse_exist()
    key_inv = False #Default value
    if mod_inv:
        key_inv = verify_key_inv(Key_Inverse())
        if key_inv:
            print("Key Verified Successfully!")
            return True
    print("Error: Key failed to get verified :(")
    print("--> Inverse_Mod_Exists: ",mod_inv)
    print("--> Key_Inverse_Exists: ",key_inv)
    print("\nYour Key is not compatible. Please change the key!\n")
    return False


def encipher(plain_txt):
    # is_key_valid()

    while (len(plain_txt))%3 != 0:    #prepairing to easily divide string into 3 equal parts/vectors
        plain_txt += " "

    # ord() and chr() for ascii conversions
    
    ascii_ls = [conv_ascii(s) for s in plain_txt]
    
    col_vecls = []
    i = int(0)
    for j in range(int(len(ascii_ls)/3)):
        col_vecls.append(np.array([ascii_ls[i], ascii_ls[i+1], ascii_ls[i+2]]))
        i+=3


    ##### Transformation to coloumn vectors done!!!!!!!!!
    #Hill cipher territory starts here
    ciphered_vecls = []
    for z in col_vecls:
        ciphered_vecls.append(z @ Key)  # @ == operator for matrix multiplication


    for x, l in enumerate(ciphered_vecls, 0):
        for y in range(0,3):
            ciphered_vecls[x][y] %= moder #Number of ASCII characters
    
    return vecls_to_str(ciphered_vecls)


def decipher(cipher_txt):
    # is_key_valid()

    #Getting column vectors ready!
    col_vecls = []
    i = int(0)
    for j in range(int(len(cipher_txt)/3)):
        col_vecls.append(np.array([conv_ascii(cipher_txt[i]), conv_ascii(cipher_txt[i+1]), conv_ascii(cipher_txt[i+2])]))
        i+=3

    #Getting Key-1 (inverse) ready!
    key_inv = Key_Inverse()

    #col_vecs and key_inv collide here :)
    plain_vecls = []
    for col_vec in col_vecls:
        plain_vecls.append((col_vec @ key_inv)%moder)


    #convert numbers to letters
    return vecls_to_str(plain_vecls)

    

if __name__ == "__main__":
    is_key_valid()

    while 1:
        print("Key: ", vlu_ls_to_str(Key.ravel()))
        ciphered = encipher(str(input("Enter Plain Text: "))) #,==44 .==46
        print("Ciphered Txt: ",ciphered)
        # print("Length: ",len(ciphered))
        # print("-----------------------------------------")
        deciphered = decipher(ciphered)
        print("Deciphered Txt: ",deciphered)
        # print("Length: ",len(deciphered))
        print("\n-----------------------------------------\n-----------------------------------------\n")

