/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        //if we reach the end / lead nodes of both the trees
        if(p==NULL && q == NULL)
        {
            return true;
        }

        if(p == NULL || q == NULL)
        {
            return false;
        }

        //recursively make calls for left and right subtree to check
        if(p->val == q->val)
        {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }

        if(p->val != q->val)
        {
            return false;
        }
        
        return false;
    }
};
