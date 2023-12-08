/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* recursiveCheck(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        //when root is NULL
        if(root == NULL)
        {
            return root;
        }

        //when p and q val is same as root val
        if(p->val == root->val || q->val == root->val)
        {
            return root;
        }

        //when p and q are children of root
        if(p->val > root->val && q->val < root->val)
        {
            return root;
        }
        if(p->val < root->val && q->val > root->val)
        {
            return root;
        }

        //when p and q is greater than root, check right subtree
        if(p->val > root->val && q->val > root->val)
        {
            return recursiveCheck(root->right, p, q);
        }

        //when p and q is lesser than root, check left subtree
        if(p->val < root->val && q->val < root->val)
        {
            return recursiveCheck(root->left, p, q);
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return recursiveCheck(root, p, q);
    }
};
