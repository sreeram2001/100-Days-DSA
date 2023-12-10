/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *righyt) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int recurs(TreeNode* root, int &count)
    {  
        if(root == NULL)
        {
            return 0;
        }

        int leftSub = recurs(root->left, count);
        int rightSub = recurs(root->right, count);

        count = max(count, leftSub+rightSub);

        return 1+max(leftSub, rightSub);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int count = 0;
        recurs(root, count);
        return count;
    }
};
