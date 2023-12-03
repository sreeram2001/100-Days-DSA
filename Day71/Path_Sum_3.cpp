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
    
    int pathSum(TreeNode* root, int targetSum) 
    {
        stack<TreeNode*> nodes;
        nodes.push(root);
        int count = 0;

        while(!nodes.empty())
        {
            TreeNode* top = nodes.top();
            nodes.pop();

            if(top != NULL)
            {
                nodes.push(top->left);
                nodes.push(top->right);
            }
            getPath(top, 0, targetSum, count);
        }

        return count;
    }

    void getPath(TreeNode* curRoot, long currSum, int targetSum, int &count)
    {
        if(curRoot == NULL)
        {
            return;
        }

        currSum += curRoot->val;
        if(currSum == targetSum)
        {
            count++;
        }

        getPath(curRoot->left, currSum, targetSum, count);
        getPath(curRoot->right, currSum, targetSum, count);
    }
};
