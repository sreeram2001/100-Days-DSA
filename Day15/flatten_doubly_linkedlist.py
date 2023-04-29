"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def flatten(self, head: 'Optional[Node]') -> 'Optional[Node]':
        #stack to store next nodes when child occurs for a node
        stack = []
        curr = head

        while(head):
            if head.child:

                #if node has child push it to stack
                if head.next:
                    stack.append(head.next)

                #next node will point to child node now to flatten
                head.next = head.child
                head.child = None
                head.next.prev = head

            #if no nodes in right or no next nodes, connect the node in stack to list
            if head.next == None and len(stack) > 0:
                head.next = stack.pop()
                head.next.prev = head       #connect prev in doubly list to previous level node

            head = head.next
        
        return curr
