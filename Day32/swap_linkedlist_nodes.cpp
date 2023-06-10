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
    ListNode* recurse(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        //create a temp node and point it to next node
        ListNode* temp = head->next;

        //make recursive call to swap
        head->next = recurse(head->next->next);

        //now put temp's next node as head
        temp->next = head;

        return temp;
    }

    ListNode* swapPairs(ListNode* head) {

        return recurse(head);
    }
};
