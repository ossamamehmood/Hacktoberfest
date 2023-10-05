class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        list = []
        min = pow(10, n - 1)
        for i in range (1, 10):
            q = [i]
            while len(q):
                num = q.pop(0)
                if num >= min:
                    list.append(num)
                    continue
                x = num % 10
                if k > 0 and x - k >= 0:
                    q.append(num * 10 + x - k)
                if x + k < 10:
                    q.append(num * 10 + x + k)
        return list
