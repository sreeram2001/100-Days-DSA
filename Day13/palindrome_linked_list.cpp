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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return true;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        //to find middle node
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *curr = slow;
        ListNode *prev = NULL;
        ListNode *nxt = NULL;

        //reversing second half
        while(curr)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        slow = prev;

        ListNode *first = head;     //first half of linkedlist
        ListNode *second = slow;    //second half of list

        //check if first half of list and reversed second half list is same
        while(first && second)
        {
            if(first->val != second->val)
            {
                return false;
            }
            first = first->next;
            second = second->next;
        }

        return true;
    }
};
