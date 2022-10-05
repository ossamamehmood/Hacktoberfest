class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        sum = 0
        l = len(digits)-1
        for idx, i in enumerate(digits):
            sum += i*(10**(l-idx))
        return map(int, str(sum+1))
