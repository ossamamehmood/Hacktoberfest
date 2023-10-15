#make all possible number list
num_start='1700000000'
#change num_start for different country region
country_code='+880'
# 0000000
# To 
# 9999999
end=99
#change end for test case
print("started....")
for i in range(0,end+1):

    f = open("number.txt", "a")
    f.write(country_code+str(int(num_start)+i)+'\n')
    f.close()

print("ended....")
