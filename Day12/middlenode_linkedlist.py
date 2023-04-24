# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:

        #Brute Force Approach
        l = 0
        curr = head

        while(curr):
            curr = curr.next
            l += 1

        #middle node index
        imid = l//2

        i = 0
        op = head
        while i < imid:
            op = op.next
            i += 1

        return op

