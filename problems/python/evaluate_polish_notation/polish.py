from typing import List
from math import trunc


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        for token in tokens:
            if token not in ["+", "-", "*", "/"]:
                stack.append(int(token))
            else:
                op2, op1 = stack.pop(), stack.pop()
                if token == "+":
                    stack.append(op1 + op2)
                elif token == "-":
                    stack.append(op1 - op2)
                elif token == "*":
                    stack.append(op1 * op2)
                elif token == "/":
                    stack.append(trunc(op1 / op2))

        return stack[0]


print(Solution().evalRPN(["2", "1", "+", "3", "*"]))  # 9
