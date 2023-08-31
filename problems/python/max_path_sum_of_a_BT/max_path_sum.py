from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left: TreeNode = left
        self.right: TreeNode = right


class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        def calculate_path_sum(node):
            if not node:
                return 0

            # negative sums should be treated as 0
            # in such case, all we should care about is the value of the node itself
            left_sum = max(calculate_path_sum(node.left), 0)
            right_sum = max(calculate_path_sum(node.right), 0)

            self.max_path_sum = max(
                self.max_path_sum, node.val + left_sum + right_sum)

            return node.val + max(left_sum, right_sum)

        self.max_path_sum = float('-inf')
        calculate_path_sum(root)
        return self.max_path_sum


keys = [20, 8, 22, 4, 12, 10, 14]

node6 = TreeNode(14)
node5 = TreeNode(10)
node4 = TreeNode(12)
node3 = TreeNode(4)
node2 = TreeNode(22, node5, node6)
node1 = TreeNode(8, node3, node4)
root = TreeNode(20, node1, node2)


print(Solution().maxPathSum(root))  # 76
