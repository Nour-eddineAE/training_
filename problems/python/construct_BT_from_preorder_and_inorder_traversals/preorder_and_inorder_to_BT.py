from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left: TreeNode = left
        self.right: TreeNode = right


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        # ? store {val: idx} pairs so wa can use them later to fetch
        # ? inorder position in O(1)
        inorder_map = {val: idx for idx, val in enumerate(inorder)}
        pre_idx = 0

        def helper(left_idx, right_idx):
            nonlocal pre_idx

            if left_idx > right_idx:
                return None

            # ? get current root's value and move to next root
            root_val = preorder[pre_idx]
            pre_idx += 1

            # ? get index in inorder traversal
            inorder_root_idx = inorder_map[root_val]

            # ? construct the current node
            root = TreeNode(root_val)

            # ? both can be either a valid node or None(in case left_idx > right_idx, i.e no value to store)
            root.left = helper(left_idx, inorder_root_idx - 1)
            root.right = helper(inorder_root_idx + 1, right_idx)

            return root

        return helper(0, len(inorder) - 1)


preorder = [3, 9, 20, 15, 7]
inorder = [9, 3, 15, 20, 7]


root = Solution().buildTree(preorder, inorder)  # [3,9,20,null,null,15,7]
