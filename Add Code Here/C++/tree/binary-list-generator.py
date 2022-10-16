# Necro(ネクロ)
# sidmishra94540@gmail.com

def binaryGenerator(n):
    pad = [0]*n
    res = []
    for _ in range(2**n):
        num = list(map(int, bin(_)[2:]))
        num = pad[:n-len(num)]+num
        res.append(num)
    return res
if __name__ == '__main__':
    print(binaryGenerator(int(input())))