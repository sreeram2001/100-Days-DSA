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
    ListNode* rotateRight(ListNode* head, int k) {
        
        ListNode *curr = head;
        int n = 0;

        while(curr)
        {
            curr = curr->next;
            n++;
        }

        vector<int> arr(n);
        curr = head;

        for(int i=0;i<n;i++)
        {
            arr[(i+k)%(n)] = curr->val;
            curr = curr->next;
        }

        curr = head;
        int it = 0;
        while(curr)
        {
            curr->val = arr[it];
            it++;
            curr = curr->next;
        }
        return head;
    }
};
