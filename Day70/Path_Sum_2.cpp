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
    vector<vector<int>> op;

    void getPath(TreeNode* root, int targetSum, vector<int> path, int currSum)
    {
        if(root == NULL)
        {
            return;
        }

        path.push_back(root->val);
        currSum += root->val;

        if(root->left == NULL && root->right == NULL)
        {
            if(currSum == targetSum)
            {
                op.push_back(path);
            }
            return;
        }

        //inorder - dfs recursive calls to left and right subtree
        getPath(root->left, targetSum, path, currSum);
        getPath(root->right, targetSum, path, currSum);

        //backtrack - remove the values for next recursive call to take place
        currSum -= root->val;
        path.pop_back();
        
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        int currSum = 0;
        getPath(root, targetSum, path, currSum);
        return op;
    }
};
