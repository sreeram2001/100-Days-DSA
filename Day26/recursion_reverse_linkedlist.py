# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        def recursive_ll(node):

            if node == None:
                return node

            if node.next == None:
                return node

            #set prev node of curr to next node of curr
            n1 = recursive_ll(node.next)
            node.next.next = node
            node.next = None
            return n1

        reverse_ll = recursive_ll(head)
        return reverse_ll





        
        
