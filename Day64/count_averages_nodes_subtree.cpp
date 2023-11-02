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

    pair<int, int> postorder(TreeNode* root, int& op)
    {
        if(root == NULL)
        {
            return {0, 0};
        }

        //recursive calls
        auto [left, lcount] = postorder(root->left, op);
        auto [right, rcount] = postorder(root->right, op);

        //sum the left, right child and root nodes
        int sumi = left + right + root->val;
        int count = lcount + rcount + 1;

        if(sumi/count == root->val)
        {
            op += 1;
        }

        return {sumi, count};
    }

    int averageOfSubtree(TreeNode* root) {
        int op = 0;
        postorder(root, op);
        return op;
    }
};
