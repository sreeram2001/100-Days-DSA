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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(root == NULL)
        {
            TreeNode* root = new TreeNode(val);
            return root;
        }

        else
        {   
            //if val less than root, goes to left subchild
            if(val < root->val)
            {
                //check if leftchild node is null or not
                if(root->left)
                {
                    insertIntoBST(root->left, val);
                }
                else
                {
                    root->left = new TreeNode(val);
                }
            }

            //if val greater than root, goes to right subchild
            if(val > root->val)
            {
                if(root->right)
                {
                    insertIntoBST(root->right, val);
                }
                else
                {
                    root->right = new TreeNode(val);
                }
            }
        }
        return root;
    }
};
