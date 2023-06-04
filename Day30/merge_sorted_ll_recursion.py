# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:

        def recur(list1, list2):

            if list1 == None and list2 == None:
                return list1

            if list1 == None:
                return list2

            if list2 == None:
                return list1

            if list1.val < list2.val:
                list1.next = recur(list1.next, list2)
                return list1

            else:
                list2.next = recur(list1, list2.next)
                return list2
        
        return recur(list1, list2)



            



        
