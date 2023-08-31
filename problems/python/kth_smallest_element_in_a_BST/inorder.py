from typing import Optional, List


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

    def inorder(self, root: TreeNode, res: List[int]) -> None:
        if not root:
            return

        self.inorder(root.left, res)
        res.append(root.val)
        self.inorder(root.right, res)

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        """
            * This solution uses an inorder traversal of a binary search tree, which is sorted by def. 
            * If the BST is modified often (i.e., we can do insert and delete operations)
                and you need to find the kth smallest frequently, how would you optimize?

                ? Storing Inorder Traversal Approach for Frequent kth Smallest Queries:

                Benefits:

                    1- Optimized Queries: Fetching the kth smallest element is constant time after constructing the list.
                    2- Reduced Query Time: Fetch operation remains efficient regardless of tree size.
                    3- Query Frequency Matters: Advantageous when there are multiple kth smallest queries after a batch of modifications.
                    4- Amortized Efficiency: If query frequency is higher than modifications, overhead of list maintenance can be acceptable.
                    5- Simplicity: Approach is simple to understand and implement.

                Trade-offs:

                    1- Memory Usage: Requires O(N) space to store traversal list.
                    2- Modification Impact: Frequent insertions and deletions can impact efficiency due to list rebuilding.
                    3- Balancing: Unbalanced tree due to modifications might reduce efficiency.
                    4- Context Matters: Effectiveness depends on the balance between queries and modifications.
        """
        res = []
        self.inorder(root, res)
        return res[k-1]


sol = Solution()
root = None
keys = [20, 8, 22, 4, 12, 10, 14]

for x in keys:
    root = sol.insert(root, x)


print(sol.kthSmallest(root, 1))  # 1
