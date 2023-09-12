from typing import List


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        rows = set()
        cols = set()
        pos_diags = set()
        neg_diags = set()
        ans = []
        board = []

        def backtrack(row):
            if row >= n:
                ans.append(board.copy())
                return

            for col in range(n):
                if (row in rows or col in cols
                    or row + col in pos_diags
                        or row - col in neg_diags):
                    continue

                rows.add(row)
                cols.add(col)
                pos_diags.add(row + col)
                neg_diags.add(row - col)
                temp = ["."] * n
                temp[col] = "Q"
                board.append("".join(temp))

                # bc
                backtrack(row + 1)

                # cleanup
                rows.remove(row)
                cols.remove(col)
                pos_diags.remove(row + col)
                neg_diags.remove(row - col)
                board.pop()

        backtrack(0)
        return ans


# [['.Q..', '...Q', 'Q...', '..Q.'], ['..Q.', 'Q...', '...Q', '.Q..']]
# Q represents the position of a queen on the chess board
print(Solution().solveNQueens(4))
