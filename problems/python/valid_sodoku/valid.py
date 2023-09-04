from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        def is_valid(nums):
            seen = set()
            for num in nums:
                if num != '.':
                    if num in seen:
                        return False
                    seen.add(num)
            return True

        # Validate rows and columns
        for i in range(9):
            if not is_valid(board[i]) or not is_valid([board[j][i] for j in range(9)]):
                return False

        # Validate 3x3 boxes
        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                sub_box = [board[x][y]
                           for x in range(i, i + 3) for y in range(j, j + 3)]
                if not is_valid(sub_box):
                    return False

        return True


board = [["5", "3", ".", ".", "7", ".", ".", ".", "."], ["6", ".", ".", "1", "9", "5", ".", ".", "."], [".", "9", "8", ".", ".", ".", ".", "6", "."], ["8", ".", ".", ".", "6", ".", ".", ".", "3"], ["4", ".", ".", "8",
                                                                                                                                                                                                      ".", "3", ".", ".", "1"], ["7", ".", ".", ".", "2", ".", ".", ".", "6"], [".", "6", ".", ".", ".", ".", "2", "8", "."], [".", ".", ".", "4", "1", "9", ".", ".", "5"], [".", ".", ".", ".", "8", ".", ".", "7", "9"]]

print(Solution().isValidSudoku(board))  # Output: true
