class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        smallest = sorted(strs, key=len)[0]
        common = ""
        for i in range(len(smallest)):
            count = len(strs)
            for j in sorted(strs, key=len):
                if j[i] == smallest[i]:
                    count -= 1
                    if count == 0:
                        common += j[i]
                else:
                    return common
        return common
