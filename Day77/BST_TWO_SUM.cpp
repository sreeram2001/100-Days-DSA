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
    vector<int> nodes;

    void inorder(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        else
        {
            if(root->left)
            {
                inorder(root->left);
            }

            nodes.push_back(root->val);

            if(root->right)
            {
                inorder(root->right);
            }
        }
    }

    bool findTarget(TreeNode* root, int k) {
        
        inorder(root);

        int start = 0, end = nodes.size()-1;
        int sumi = 0;

        while(start < end)
        {
            sumi = nodes[start] + nodes[end];

            if(sumi == k)
            {
                return true;
            }
            else if(sumi > k)
            {
                end--;
            }
            else
            {
                start++;
            }
        }
        return false;
    }
};
