def search(list, num):
    for i in range(len(list)):
        if list[i]==num:
            return i
    return -1
#inputing a list
li = list(map(int, input().split())
#input the no to be searched
num = int(input())
#finding value
t = search(list, num)
print(t)
