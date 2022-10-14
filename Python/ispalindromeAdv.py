from collections import Counter
def count(l):
    # c = Counter(l)
    freq = {}
    for i in l:
        if i in freq:
            freq[i] +=1
        else:
            freq[i] = 1
    return freq
    print(c)

def isPalindrome(l):
    c = count(l)
    odd = 0
    for i in c.values():
        if i%2 != 0:
            odd = odd +1
            if  odd >1:
                return False
    return True
print(isPalindrome(',aaabbbb,'))