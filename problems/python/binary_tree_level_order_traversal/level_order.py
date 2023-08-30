from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []

        result = []
        # * Initial level
        level = [root]

        while level:
            next_level = []
            level_res = []
            for node in level:
                level_res.append(node.val)
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)

            result.append(level_res)
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

print(Solution().levelOrder(root))  # [[4], [3, 6], [1, 5], [2]]
