from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left: TreeNode = left
        self.right: TreeNode = right
        self.lCount = 0


class Solution:
    def insert(self, root, x):
        if (root == None):
            return TreeNode(x)

        if (x < root.val):
            root.left = self.insert(root.left, x)
            root.lCount += 1

        elif (x > root.val):
            root.right = self.insert(root.right, x)

        return root

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        """
            Find the k-th smallest element in a binary search tree using an optimized approach.

            This solution employs an optimized in-order traversal of the binary search tree.
            By keeping track of the count of visited nodes, the traversal is stopped as soon as
            the k-th smallest element is found. This approach reduces both time complexity and
            space usage compared to collecting all elements in a list and then finding the k-th smallest.

            Args:
                root (Optional[TreeNode]): The root of the binary search tree.
                k (int): The desired rank of the element to find (1-based).

            Returns:
                int: The k-th smallest element in the binary search tree.
        """
        self.count = 0
        self.result = None
        self.inorder(root, k)
        return self.result

    def inorder(self, node, k):
        if not node or self.count >= k:
            return

        # Traverse left
        self.inorder(node.left, k)

        # Process current node
        self.count += 1
        if self.count == k:
            self.result = node.val

        # Traverse right
        self.inorder(node.right, k)


sol = Solution()
root = None
keys = [20, 8, 22, 4, 12, 10, 14]

for x in keys:
    root = sol.insert(root, x)


print(sol.kthSmallest(root, 1))  # 1
