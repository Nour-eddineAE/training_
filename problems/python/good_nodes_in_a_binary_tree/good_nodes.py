from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left: TreeNode = left
        self.right: TreeNode = right


class Solution:
    def helper(self, root: TreeNode, largest):
        if not root:
            return 0

        good = 0
        if root.left:
            if root.left.val >= largest:
                good += 1 + self.helper(root.left, root.left.val)
            else:
                good += self.helper(root.left, largest)

        if root.right:
            if root.right.val >= largest:
                good += 1 + self.helper(root.right, root.right.val)
            else:
                good += self.helper(root.right, largest)
        return good

    def goodNodes(self, root: TreeNode) -> int:
        """
          * A node is considered 'good' if there are no nodes with values greater than its value
          * anywhere on the path from the root to that node.
        """
        return 1 + self.helper(root, root.val)


node6 = TreeNode(5)
node5 = TreeNode(1)
node4 = TreeNode(3)
node3 = TreeNode(4, node5, node6)
node2 = TreeNode(1, node4)
root = TreeNode(3, node2, node3)


print(Solution().goodNodes(root))  # 4
