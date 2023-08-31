class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left: TreeNode = left
        self.right: TreeNode = right
        self.lCount = 0


def insert(root, x):

    if (root == None):
        return TreeNode(x)

    # If a node is inserted in left subtree,
    # then lCount of this node is increased.
    # For simplicity, we are assuming that
    # all keys (tried to be inserted) are
    # distinct.
    if (x < root.val):
        root.left = insert(root.left, x)
        root.lCount += 1

    elif (x > root.val):
        root.right = insert(root.right, x)

    return root
