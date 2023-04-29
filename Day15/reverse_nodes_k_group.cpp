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
    ListNode* reverseKGroup(ListNode* head, int k) {

        vector<int> v;
        ListNode *cur = head;

        while(cur)
        {
            v.push_back(cur->val);
            cur = cur->next;
        }

        int i=0;
        while(i < v.size() - v.size()%k)
        {
            reverse(v.begin()+i,v.begin()+i+k);
            i = i + k;
        }

        i = 0;
        cur = head;
        while(cur)
        {
            cur->val = v[i];
            i++;
            cur = cur->next;
        }

        return head;

    }
};
