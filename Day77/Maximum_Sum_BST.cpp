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
    int maxi = 0;

    bool isValidBST(TreeNode* root, int& sumi)
    {
        sumi = 0;
        if(root == NULL)
        {
            return true;
        }

        stack<TreeNode*> st;
        TreeNode* prev_node = NULL;

        while(root != NULL || !st.empty())
        {
            while(root != NULL)
            {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            sumi = sumi + root->val;
            st.pop();

            if( prev_node != NULL &&  prev_node->val >= root->val)
            {
                return false;
            }

            prev_node = root;
            root = root->right;
        }
        return true;
    }

    void inorder(TreeNode* root, int& sumi)
    {
        if(root == NULL)
        {
            return;
        }

        if(root->left)
        {
            inorder(root->left, sumi);
        }

        if(isValidBST(root, sumi))
        {
            maxi = max(maxi, sumi);
        }
        
        if(root->right)
        {
            inorder(root->right, sumi);
        }
    } 

    int maxSumBST(TreeNode* root) {

        int sumi = 0;
        inorder(root, sumi);
        return maxi;
    }
};
