from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self, diameter=0) -> None:
        self.diameter = diameter

    # Calculates depth at a specefic node and updates the diameter
    def find_diam(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        left_depth = self.find_diam(root.left)
        right_depth = self.find_diam(root.right)

        self.diameter = max(left_depth + right_depth, self.diameter)

        return 1 + max(left_depth, right_depth)

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        self.find_diam(root)

        return self.diameter


root = TreeNode(1)
node2 = TreeNode(1)
node3 = TreeNode(1)
node4 = TreeNode(1)
node5 = TreeNode(1)
node6 = TreeNode(1)
node7 = TreeNode(1)
node8 = TreeNode(1)
node9 = TreeNode(1)
node10 = TreeNode(1)
node11 = TreeNode(2)


root.right = node2
node2.right = node3
node3.right = node4
node4.right = node5
node5.right = node6
node6.right = node7
node7.right = node8
node8.right = node9
node9.right = node10
node10.left = node11

print(Solution().diameterOfBinaryTree(root))  # 10
