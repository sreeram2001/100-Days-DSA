/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        //find the length of linkedlist
        int a=0, b=0;
        ListNode *l1 = headA;
        ListNode *l2 = headB;

        while(l1)
        {
            l1 = l1->next;
            a++;
        }
        while(l2)
        {
            l2 = l2->next;
            b++;
        }

        //to find diff in length in both list
        int diff = abs(a-b);

        //now traverse the linkedlist which is large until diff
        if(a > b)
        {
            while(diff)
            {
                headA = headA->next;
                diff--;
            }
        }
        else
        {
            while(diff)
            {
                headB = headB->next;
                diff--;
            }
        }

        //now traverse both the list to check if they intersect
        while(headA && headB)
        {   
            //if they intersect return the node
            if(headA == headB)
            {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }
};
