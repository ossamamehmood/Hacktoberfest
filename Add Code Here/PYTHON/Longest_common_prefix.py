#https://leetcode.com/problems/longest-common-prefix/
class Solution(object):
    def are_equal(self, strs, index):
        for i in range(1, len(strs)):
            if index >= len(strs[i]) or strs[i][index] != strs[0][index]:
                return False
        return True

    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""

        min_length = len(strs[0])
        for i in range(1, len(strs)):
            min_length = min(min_length, len(strs[i]))

        longest_prefix = ""
        for i in range(min_length):
            if self.are_equal(strs, i):
                longest_prefix += strs[0][i]
            else:
                break

        return longest_prefix
