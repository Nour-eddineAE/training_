from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSame(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not root and not subRoot:
            return True

        if not root or not subRoot:
            return False

        return root.val == subRoot.val and self.isSame(root.left, subRoot.left) and self.isSame(root.right, subRoot.right)

    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not root:
            return False

        if self.isSame(root, subRoot):
            return True

        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)


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

print(Solution().isSubtree(root, node5))  # True
