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

    ListNode *rev = NULL;
    bool palindr = true;

    void recurse(ListNode * head)
    {
        if(head == NULL)
        {
            return;
        }

        recurse(head->next);
        if(rev != NULL)
        {
            if(rev->val != head->val)
            {
                palindr = false;
            }
        }

        rev = rev->next;
    }


    bool isPalindrome(ListNode* head) {
        rev = head;
        recurse(head);
        
        //returns true or false
        return palindr;
    }
};
