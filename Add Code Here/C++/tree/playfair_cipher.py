msg, new_msg = "", ""
a = [[0 for i in range(5)]for i in range(5)]

def input_f(text, key):
    inp = []
    lst_inp = key.split()
    for item in lst_inp:
        inp += item

    a = key_table(inp)

    c_msg = text
    msg = ""
    for i in c_msg:
        msg += i

    new_msg = "".join([i for i in c_msg])

    if 'j' in msg:
        msg = msg.replace('j', 'i')
    if 'J' in msg:
        msg = msg.replace('J', 'I')

    chunks = converted_chunks(msg)

    return chunks, a

def key_table(inp):
    key = list(dict.fromkeys(inp))
    k = 0
    x = 65
    a = [[0 for i in range(5)]for i in range(5)]
    for i in range(5):
        for j in range(5):
            if k < len(key):
                a[i][j] = key[k].upper()
                k += 1
            elif not any(chr(x) in y for y in a) and chr(x) != 'J':
                a[i][j] = chr(x)
                x += 1
            else:
                while any(chr(x) in y for y in a) or chr(x) == 'J':
                    x += 1
                a[i][j] = chr(x)
    return a

def converted_chunks(msg):
    msg_list =  []
    for item in msg:
        msg_list += item

    chunks = []
    i = 0
    while i < len(msg_list):
        if i == len(msg_list)-1:
            chunks.append([msg_list[i].upper(), 'X'])
        elif msg_list[i] != msg_list[i + 1]:
            chunks.append([msg_list[i].upper(), msg_list[i+1].upper()])
            i += 1
        else:
            chunks.append([msg_list[i].upper(), 'X'])
        i += 1
    return chunks

def find_coord(c, a):
    for i in range(5):
        for j in range(5):
            if a[i][j] == c:
                return i, j

def check_num_spl(item):
    return item[0].isalpha() and item[1].isalpha()

def encrypt(txt, key):
    spl = ['!','@','#','$','%','^','&','*','(',')','<','~',':',';','<','>','?','/']
    for i in key:
        if i in spl:
            key = key.replace(i,"")
    if key == "":
        key = "ABCD"
    chunks, a = input_f(txt, key)
    enc_text = ""
    for item in chunks:
        if not check_num_spl(item):
            enc_text += item[0] + item[1]
        else:
            st = ""
            x1, y1 = find_coord(item[0], a)
            x2, y2 = find_coord(item[1], a)
            if y1 == y2:
                enc_text += a[(x1+1)%5][y1] + a[(x2+1)%5][y1]
            elif x1 == x2:
                enc_text += a[x1][(y1+1)%5] + a[x2][(y2+1)%5]
            else:
                st += a[x2][y1] + a[x1][y2]
                enc_text += st[::-1]
    return enc_text

def decrypt(txt, key): 
    spl = ['!','@','#','$','%','^','&','*','(',')','<','~',':',';','<','>','?','/']
    for i in key:
        if i in spl:
            key = key.replace(i,"")
    if key == "":
        key = "ABCD"

    chunks, a = input_f(txt, key)

    dec_text = ""

    for item in chunks:
        if not check_num_spl(item):
            dec_text += item[0] + item[1]
        else:
            st = ""
            x1, y1 = find_coord(item[0], a)
            x2, y2 = find_coord(item[1], a)
            if y1 == y2:
                dec_text += a[x1-1][y1] + a[x2-1][y1]
            elif x1 == x2:
                dec_text += a[x1][y1-1] + a[x2][y2-1]
            else:
                dec_text += a[x1][y2] + a[x2][y1]
    if 'X' in dec_text:
        dec_text = dec_text.replace('X', '')
    return dec_text

def main():
    text = input("Enter your text:").lower()
    key = input("Enter your key:").lower()
    encrypted = encrypt(text, key)
    decrypted = decrypt(encrypted, key)
    print(f"Encrypted Message: {encrypted}")
    print(f"Decrypted Message: {decrypted}")

if __name__ == "__main__":
    main()
