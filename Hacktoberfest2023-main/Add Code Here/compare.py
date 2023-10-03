file_1 = open('file1.txt', 'r')
file_2 = open('file2.txt', 'r')
 
print("Comparing files ", " @ " + 'file1.txt', " # " + 'file2.txt', sep='\n')
 
file_1_line = file_1.readline()
file_2_line = file_2.readline()

line_no = 1
 
print()
 
with open('file1.txt') as file1:
    with open('file2.txt') as file2:
        same = set(file1).intersection(file2)
 
print("Common Lines in Both Files")
 
for line in same:
    print(line, end='')
 
print('\n')
print("Difference Lines in Both Files")
while file_1_line != '' or file_2_line != '':
 

    file_1_line = file_1_line.rstrip()
    file_2_line = file_2_line.rstrip()
 

    if file_1_line != file_2_line:
       

        if file_1_line == '':
            print("@", "Line-%d" % line_no, file_1_line)
        else:
            print("@-", "Line-%d" % line_no, file_1_line)
             

        if file_2_line == '':
            print("#", "Line-%d" % line_no, file_2_line)
        else:
            print("#+", "Line-%d" % line_no, file_2_line)
 
        print()
 

    file_1_line = file_1.readline()
    file_2_line = file_2.readline()
 
    line_no += 1
 
file_1.close()
file_2.close()