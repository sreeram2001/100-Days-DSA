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

    vector<string> op;

    void getPath(TreeNode* root, string ans)
    {
        if(root == NULL)
        {
            return;
        }

        ans += (ans.size() ? "->" : "") + to_string(root->val);

        //if you have reached leaf node
        if(root->left == NULL && root->right==NULL)
        {
            op.push_back(ans);
        }

        getPath(root->left, ans);
        getPath(root->right, ans);
    }


    vector<string> binaryTreePaths(TreeNode* root) {
        string ans = "";
        getPath(root, ans);
        return op;
    }
};
