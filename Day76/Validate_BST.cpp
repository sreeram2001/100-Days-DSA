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

    bool isValidBST(TreeNode* root) {
        //if root is NULL
        if (root == NULL) return true;
        //we use stack to store nodes as we iterate
        stack<TreeNode*> st;

        TreeNode* prev_node = NULL;

        while( root != NULL || !st.empty())
        {
            //ITERATE UNTIL LEFT NODE BECOMES NULL
            while(root != NULL)
            {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();

            //check to see if its current node is less than its previous node
            if( prev_node != NULL && prev_node->val >= root->val)
            {
                return false;
            }

            //update the previous node
            prev_node = root;

            //move to next right node
            root = root->right;
        }
        return true;
    }
};
