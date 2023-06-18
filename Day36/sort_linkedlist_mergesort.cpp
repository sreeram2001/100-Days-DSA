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

    ListNode* getMid(ListNode* head)
    {
        //using fast and slow pointer approach to get middle node
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode *op = new ListNode();
        ListNode *tmp = op;

        while (left && right)
        {
            if(left->val < right->val)
            {
                tmp->next = left;
                left = left->next;
            }
            else
            {
                tmp->next = right;
                right = right->next;
            }
            tmp = tmp->next;
        }
        
        //leftover nodes
        if(left)
        {
            tmp->next = left;
        }
        if(right)
        {
            tmp->next = right;
        }

        return op->next;
    }

    ListNode* sortList(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        //split left half and right half
        ListNode* left = head;
        ListNode* right = getMid(head);

        ListNode* temp = right->next;
        //to split array into two halves, we make next pointer null
        right->next = NULL;
        right = temp;

        //recursive calls to divide list
        left = sortList(left);
        right = sortList(right);

        //recursive call to merge/conquer
        return merge(left, right); 
    }


};
