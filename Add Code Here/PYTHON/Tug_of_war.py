def tugOfWarHelper(i, subsetSum, cnt, totalSum, arr, n):

    # base case
    if (i == n or cnt >= (n // 2)):

        if (cnt == (n // 2)):
            return abs(totalSum - 2 * subsetSum)

        return sys.maxsize

    ans = sys.maxsize

    # don't take ith student
    ans = min(ans, tugOfWarHelper(i + 1, subsetSum, cnt, totalSum, arr, n))

    # take ith student
    ans = min(ans, tugOfWarHelper(i + 1, subsetSum +
                                  arr[i], cnt + 1, totalSum, arr, n))

    return ans


def tugOfWar(arr, n):

    totalSum = 0

    for i in range(n):
        totalSum += arr[i]

    # call the recursive function
    ans = tugOfWarHelper(0, 0, 0, totalSum, arr, n)
    return ans