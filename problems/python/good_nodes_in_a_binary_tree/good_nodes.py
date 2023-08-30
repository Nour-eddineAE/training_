from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left: TreeNode = left
        self.right: TreeNode = right


class Solution:
    def good_node(self, root, largest):
        if not root:
            return 0

        largest = max(largest, root.val)

        if root.val >= largest:
            return 1 + self.good_node(root.left, largest) + self.good_node(root.right, largest)

        return self.good_node(root.left, largest) + self.good_node(root.right, largest)

    def goodNodes(self, root):
        """
          * A node is considered 'good' if there are no nodes with values greater than its value
          * anywhere on the path from the root to that node.
        """
        return self.good_node(root, float('-inf'))


node6 = TreeNode(5)
node5 = TreeNode(1)
node4 = TreeNode(3)
node3 = TreeNode(4, node5, node6)
node2 = TreeNode(1, node4)
root = TreeNode(3, node2, node3)


print(Solution().goodNodes(root))  # 4
