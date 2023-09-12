from typing import List
from collections import defaultdict, Counter


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        len_rows = len(board)
        len_cols = len(board[0])
        path = set()

        def backtrack(row, col, pos):
            if len(word) == pos:
                return True
            if (min(row, col) < 0 or row >= len_rows or col >= len_cols
                    or board[row][col] != word[pos] or (row, col) in path):
                return False

            path.add((row, col))
            res = (backtrack(row, col + 1, pos + 1) or backtrack(row, col - 1, pos + 1)
                   or backtrack(row + 1, col, pos + 1) or backtrack(row - 1, col, pos + 1))
            path.remove((row, col))

            return res

        count = defaultdict(int, sum(map(Counter, board), Counter()))
        if count[word[0]] > count[word[-1]]:
            word = word[::-1]

        for row in range(len_rows):
            for col in range(len_cols):
                if backtrack(row, col, 0):
                    return True
        return False


board = [["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]]
word = "ABCCED"
print(Solution().exist(board, word))  # True
