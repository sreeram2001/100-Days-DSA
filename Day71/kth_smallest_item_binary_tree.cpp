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
    int op = -1;

    void inorder(TreeNode* root, int k, int& count)
    {   
        if(root != NULL)
        {
            if(root->left != NULL)
            {
                inorder(root->left, k, count);
            }

            count++;
            if(count == k)
            {
                op = root->val;
            }

            if(root->right != NULL)
            {
                inorder(root->right, k, count);
            }
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        inorder(root, k, count);
        return op;
    }
};
