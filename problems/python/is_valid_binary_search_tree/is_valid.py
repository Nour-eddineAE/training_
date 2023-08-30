from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left: TreeNode = left
        self.right: TreeNode = right


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def validate(node: Optional[TreeNode], smallest, largest) -> bool:
            if not node:
                return True

            elif node.val <= smallest or node.val >= largest:
                return False

            else:
                return (validate(node.left, smallest, node.val) and
                        validate(node.right, node.val, largest))

        return validate(root, float('-inf'), float('inf'))


node5 = TreeNode(7)
node4 = TreeNode(3)
node3 = TreeNode(6, node4, node5)
node2 = TreeNode(4)
root = TreeNode(5, node2, node3)


print(Solution().isValidBST(root))  # False
