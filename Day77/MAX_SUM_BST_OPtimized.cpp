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

    class dataStruct
    {
        public:
        int sum;
        int maxi;
        int mini;
        bool isBST;
    };

    dataStruct inorder(TreeNode* root, int& val)
    {   
        //if root is null it is bst with sum 0, return the data structure
        if(root == NULL)
        {
            return {0, INT_MIN, INT_MAX, true};
        }

        dataStruct left = inorder(root->left, val);
        dataStruct right = inorder(root->right, val);

        //this currNode is considered as root
        dataStruct currNode;

        //currsum of a node includes its left, right subtree and the node itself
        currNode.sum = left.sum + right.sum + root->val;
        //minimum value of a node lies in left subtree
        currNode.mini = min(root->val, left.mini);
        //maximum value of a node lies in right subtre
        currNode.maxi = max(root->val, right.maxi);

        if(left.isBST && right.isBST && (root->val > left.maxi && root->val < right.mini ))
        {
            currNode.isBST = true;
        }
        else
        {
            currNode.isBST = false;
        }

        if(currNode.isBST)
        {
            val = max(val, currNode.sum);
        }

        return currNode;
    }

    int maxSumBST(TreeNode* root) {

        int op = 0;
        inorder(root, op);
        return op;
    }
};
