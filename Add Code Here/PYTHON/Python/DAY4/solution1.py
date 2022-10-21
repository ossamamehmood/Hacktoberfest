class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        parantheses = {
            ")":"(",
            "]":"[",
            "}":"{"
        }
        for i in s:
            l = len(stack)
            if l == 0:
                stack.append(i)
            else:
                if i not in parantheses.keys():
                    stack.append(i)
                else:
                    if stack[l-1] == parantheses[i]:
                        stack.pop(l-1)
                    else:
                        return False
        if len(stack) == 0:
            return True
        else:
            return False
