# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        
        if list1 == None and list2 == None:
            return list1

        op = ListNode(0)
        head = op

        while list1 != None and list2 != None:

            if list1.val < list2.val:
                op.next = list1
                list1 = list1.next

            elif list1.val >= list2.val:
                op.next = list2
                list2 = list2.next
                
            op = op.next
            
        if list1 == None:
            op.next = list2
        elif list2 == None:
            op.next = list1

        return head.next

         

        
