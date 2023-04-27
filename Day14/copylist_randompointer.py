"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':

        if not head:
            return None

        dict = {}
        prev_node = None
        curr = head

        while(curr):

            #shallow copy
            dict[curr] = copy.copy(curr)

            #to set node.next
            if prev_node:
                dict[prev_node].next = dict[curr]

            prev_node = curr
            curr = curr.next

        #to set random pointers
        curr = head
        while(curr):
            if curr.random:
                dict[curr].random = dict[curr.random]
            curr = curr.next

        return dict[head]
