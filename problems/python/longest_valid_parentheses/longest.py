class Solution:
    def longestValidParentheses(self, s: str) -> int:
        s = s[s.find('('): s.rfind(')') + 1]

        stack = []
        res = [0] * len(s)

        for i, char in enumerate(s):
            if char == '(':
                stack.append(i)
            elif char == ')':
                if stack:
                    res[stack.pop()] = 1
                    res[i] = 1
        longest = 0
        temp = 0
        for val in res:
            if val != 0:
                temp += 1
            else:
                longest = max(longest, temp)
                temp = 0

        return max(temp, longest)

    # Using one stack => less processing, les memory use
    def longestValidParentheses_(self, s: str) -> int:
        s = s[s.find('('): s.rfind(')') + 1]

        stack = [-1]
        res = 0
        for i, char in enumerate(s):
            if char == "(":
                stack.append(i)
            else:
                stack.pop()
                if stack:
                    res = max(res, i - stack[-1])
                else:
                    stack.append(i)
        return res


st = "(()(()(()))()()"
print(Solution().longestValidParentheses(st))  # 14
print(Solution().longestValidParentheses_(st))  # 14
