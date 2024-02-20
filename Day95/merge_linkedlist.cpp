/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL)
        {
            return list2;
        }

        if(list2 == NULL)
        {
            return list1;
        }

        ListNode *op = new ListNode(0);
        ListNode *head = op;
        while(list1 != NULL && list2 != NULL)
        {
            if(list1->val < list2->val)
            {
                op->next = list1;
                list1 = list1->next;
            }
            else
            {
                op->next = list2;
                list2 = list2->next;
            }

            op = op->next;
        }

        if(list1 == NULL && list2 != NULL)
        {
            op->next = list2;
        }
        else if(list2 == NULL && list1 != NULL)
        {
            op->next = list1;
        }

        return head->next;
    }
};
