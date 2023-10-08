# # Section 1 : Basics 

# # This is for only read the file.
# with open("test.txt", 'r') as f:
#     f.read()

# # This write attribute can change or overwrite the existing one.
# with open ("test.txt", 'w') as f:
#     f.write("This is my new data")

# # This 'a' = append attribute append or add new data into existing one without erase the older data.
# with open("test.txt", 'a') as f :
#     f.write('\n' +  " data122")


# # Section 2 : Reading a file line by line

# # Read the data with for loop
# with open("test.txt", 'r') as fp:
#     for f in fp:
#         print(f)

# # Read the data with while loop

# with open("test.txt", 'r') as fp:
#     while True:
#         cur_line = fp.readline()
#         if cur_line == '':
#             break
#         print(cur_line)



# Section 3 : Getting full contents of a file

'''The "With" keyword is most preferred because it ensure the close command
    to the file we do not need to write close command for the closing, 
    it automatically closed once the reading or writing has been completed.'''

# Example:

# with open("test.txt", 'r') as f:
#     content = f.read()

# print(content)


''' I can also manually put the open and close command '''

# Example:

# f = open("test.txt", 'r')
# content =  f.read()
# print(content)
# f.close()



# Section 4 : Copying content one file to another file

with open("test.txt", 'r') as fm, open('test2.txt', 'w') as f: # Before comma the copying after comma is pasted file which were copied from the before comma

    for line in fm:
        f.write(line)

import shutil
src = "test.txt"
dst = 'test2.txt'
shutil.copy(src, dst)