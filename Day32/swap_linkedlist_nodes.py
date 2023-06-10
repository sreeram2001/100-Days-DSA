# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:

        curr = head
        op = []

        while curr:
            op.append(curr.val)
            curr = curr.next

        opll = head

        for i in range(0,len(op)-1,2):
            op[i], op[i+1] = op[i+1], op[i]

        for i in range(len(op)):
            opll.val = op[i]
            opll = opll.next

        return head




            
