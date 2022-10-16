myList = [1, 20, 30, 44, 56, 57, 8, 19, 10, 31, 12, 13, 14, 35, 16, 27, 58, 19, 21]



# method 1
def isUnique(list):
    d = {}
    for i in list:
        d.setdefault(i, 0)
        d[i] += d[i] + 1

    for i in d:
        if d[i] > 1:
            print(f"Key:{i}=>value:{d[i]}")
            return False
    return True


isUnique(myList)


# method 2
'''for i in range(len(myList)):
    for j in range(i + 1, len(myList)):
        if myList[i] == myList[j]:
            print(myList[i])
            print(False)
            break'''