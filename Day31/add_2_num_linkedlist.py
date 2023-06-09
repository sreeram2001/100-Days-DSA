# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        #recursively reverse the nodes first
        def recurse(node1, node2, carry):

            if node1 == None and node2 == None and carry == 0:
                return None

            #if list1 is empty, make its next nodes to 0
            if node1 == None:
                node1 = ListNode(0)

            if node2 == None:
                node2 = ListNode(0)

            #add the carry and each nodes values
            sumi = node1.val + node2.val + carry

            #Create a new node with sumi value
            node = ListNode(sumi%10)

            node.next = recurse(node1.next, node2.next, sumi//10)
            return node

        rev = recurse(l1, l2, 0)
        return rev
