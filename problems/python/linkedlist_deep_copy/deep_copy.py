from typing import Optional

# Definition for a Node.


class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        # ? immidiate break
        if head == None:
            return None

        it = head
        headCopy: 'Node' = Node(0)
        curr: 'Node' = headCopy
        references = {}

        # ? create the linked list and map new nodes to original nodes
        while it is not None:
            curr.val = it.val

            references[it] = curr

            if it.next is not None:
                curr.next = Node(0)
                curr = curr.next

            it = it.next

        # ? fill random pointers
        it = head
        curr = headCopy

        while it is not None:
            if it.random is not None:
                curr.random = references[it.random]

            it = it.next
            curr = curr.next

        return headCopy


node = Node(1)
node.next = Node(2)
node.next.next = Node(3)
node.next.random = node


it = Solution().copyRandomList(node)

while it is not None:
    print("current val: ", it.val)
    if it.random is not None:
        print("  random val: ", it.random.val)
    it = it.next
