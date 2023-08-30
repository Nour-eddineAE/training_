from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        """
        ? This an iterative appraoch, that allows to get the rightmost node for every level.
        """

        if not root:
            return []

        result = []
        level = [root]

        while level:
            result.append(level[-1].val)
            next_level = []
            for node in level:
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
            level = next_level

        return result


root = TreeNode(4)
node2 = TreeNode(3)
node3 = TreeNode(6)
node4 = TreeNode(1)
node5 = TreeNode(5)
node6 = TreeNode(2)


root.left, root.right = node2, node3
node2.left = node4
node3.left = node5
node4.right = node6

print(Solution().rightSideView(root))  # [4, 6, 5, 2]
