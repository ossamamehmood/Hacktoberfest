import function as f
import tkinter as tk

#thid function is called when the encrypt button is pressed
def encrypter(message, key):
    output_text.delete('1.0', tk.END)           #clean the output section
    forward = 0
    backward = len(message) - 1

    for i in message:                           #take each character of the message one by one
        for j in key:                           #encrypt that chracter with each chracter of the key

            val1, val2 = 0, 0
            bin_val = f.dec_to_bin_8bit(ord(i)) #convert that char to bin then bin to decemal

            #now the below if statements break the 8-bit binary to two 4 bit binary for the substitution process
            #first half binary as follow
            if bin_val[0] == '1':
                val1 += 8
            if bin_val[1] == '1':
                val1 += 4
            if bin_val[2] == '1':
                val1 += 2
            if bin_val[3] == '1':
                val1 += 1

            #second half binary as follow
            if bin_val[4] == '1':
                val2 += 8
            if bin_val[5] == '1':
                val2 += 4
            if bin_val[6] == '1':
                val2 += 2
            if bin_val[7] == '1':
                val2 += 1

            #here do all the encryption process like substitution, permutation and then exor with key
            i = chr(ord(j) ^ f.bin_to_dec(f.permutation(f.two_char_to_bin(f.substitution(val1), f.substitution(val2)))))

        #here if replace the char which is below value 33 because it dosent have a printable symbol,
        # these are some special function character
        if ord(i) < 33:
            k = ord(i) + 256
            i = chr(k)

        #same goes for the chracter between 126 and 161
        if 126 < ord(i) < 161:
            k = ord(i) + 162
            i = chr(k)

        #here the encrypted character are joined to make a string
        message = message[:forward] + i + message[:backward]
        forward += 1
        backward -= 1

    #here we change the output label as Encrypted message
    label['text'] = 'Encrypted\nMessage'
    output_text.insert(1.0, message)


def decrypt(message, key):
    output_text.delete('1.0', tk.END)                   #clean the output section
    forward = 0
    backward = len(message) - 1

    for i in message:                               #taking each character of the encryped message to get decrpted
        pos = len(key) - 1

        #here the reverse of the replacing character done on line 42 to 49 is done
        if 256 <= ord(i) <= 288:
            k = ord(i) - 256
            i = chr(k)

        if 289 <= ord(i) <= 322:
            k = ord(i) - 162
            i = chr(k)

        for j in key:                               #here the encryped character is decryped using each character of the key
            binary = f.reverse_permutation(f.dec_to_bin_8bit(ord(i) ^ ord(key[pos])))
            i = chr(f.bin_to_dec(f.dec_to_bin_4bit(f.reverse_substitution(f.bin_to_dec_4bit(binary[0:4]))) + f.dec_to_bin_4bit(
                f.reverse_substitution(f.bin_to_dec_4bit(binary[4:8])))))
            pos -= 1
        message = message[:forward] + i + message[:backward]
        forward += 1
        backward -= 1

    #change the output label to Decryped message
    label['text'] = 'Decrypted\nMessage'
    output_text.insert(1.0, message)


root = tk.Tk()              #create tkinter window

#creating the tkinter widgets
canvas = tk.Canvas(root, height=250, width=650)
head_label = tk.Label(canvas, text='Message Encrypter', font=('verdana', 20))
message_label = tk.Label(canvas, text='Message: ', font=('verdana', 15))
key_label = tk.Label(canvas, text='Key: ', font=('verdana', 15))
message_entry = tk.Entry(canvas, width=40, font=('verdana', 15))
key_entry = tk.Entry(canvas, width=40, font=('verdana', 15))
output_label = tk.Label(canvas, text='OutPut ↓', font=('verdana', 15))
label = tk.Label(canvas, text='Encrypted\nMessage', font=('verdana', 15))
output_text = tk.Text(canvas, height=1, width=40, borderwidth=1, font=('verdana', 15))
encrypt_button = tk.Button(canvas, text='Encrypt', font=('verdana', 15), command=lambda: encrypter(message_entry.get(), key_entry.get()))
decrypt_button = tk.Button(canvas, text='Decrypt', font=('verdana', 15), command=lambda: decrypt(message_entry.get(), key_entry.get()))


#placing the widgetes
canvas.pack()
head_label.place(y=1, relx=0.35)
message_label.place(x=3, y=50, anchor='w')
key_label.place(x=3, y=85, anchor='w')

message_entry.place(x=120, y=40)
key_entry.place(x=120, y=75)

output_label.place(y=115, relx=0.45)
label.place(x=3, y=170, anchor='w')
output_text.place(x=120, y=150)
encrypt_button.place(x=350, y=200)
decrypt_button.place(x=470, y=200)

root.mainloop()

