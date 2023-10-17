def max_of_list(xs):
    if len(xs) ==1:
        return xs[0]
    elif xs[0]> xs[1]:
        xs.pop(1)
        return max_of_list(xs)
    else:
        xs.pop(0)
        return max_of_list(xs)
def main():
    print(max_of_list([4,3,5,192.6,14, -2]))

main()
