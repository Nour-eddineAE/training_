from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        return 1 + max(self.maxDepth(root.left),
                       self.maxDepth(root.right))


root = TreeNode(1)
node2 = TreeNode(2)
node3 = TreeNode(2)
node4 = TreeNode(3)
node5 = TreeNode(3)
node6 = TreeNode(4)
node7 = TreeNode(4)

root.left, root.right = node2, node3
node2.left, node2.right = node4, node5
node4.left, node4.right = node6, node7

print(Solution().maxDepth(root))  # 4
