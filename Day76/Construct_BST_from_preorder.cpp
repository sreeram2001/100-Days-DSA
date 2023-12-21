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

    void insert(TreeNode* root, int val)
    {
        //if value is less, push it to left subtree
        if(root->val > val)
        {
            if(root->left)
            {
                insert(root->left, val);
            }
            else
            {
                root->left = new TreeNode(val);
            }
        }

        else if(root->val < val)
        {
            if(root->right)
            {
                insert(root->right, val);
            }
            else
            {
                root->right = new TreeNode(val);
            }
        }
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);

        if(preorder.size()==1)
        {
            return root;
        }

        for(int i=1;i<preorder.size();i++)
        {
            insert(root, preorder[i]);
        }

        return root;
    }
};
