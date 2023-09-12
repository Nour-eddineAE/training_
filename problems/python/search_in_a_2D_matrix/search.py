from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row_start, row_end = 0, len(matrix) - 1

        while row_start <= row_end:
            row_mid = (row_start + row_end) // 2

            if matrix[row_mid][0] <= target and matrix[row_mid][-1] >= target:
                col_start, col_end = 0, len(matrix[0]) - 1

                while col_start <= col_end:
                    col_mid = (col_start + col_end) // 2

                    if matrix[row_mid][col_mid] == target:
                        return True
                    elif matrix[row_mid][col_mid] > target:
                        col_end = col_mid - 1
                    else:
                        col_start = col_mid + 1

                return False
            elif matrix[row_mid][0] > target:
                row_end = row_mid - 1
            else:
                row_start = row_mid + 1

        return False


matrix = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]]
target = 3

# the overall time complexity should be log(n*m) where n and m represent the size of the matrix
# True
print(Solution().searchMatrix(matrix, target))
