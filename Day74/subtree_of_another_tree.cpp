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

    bool compareNodes(TreeNode* root, TreeNode* subRoot)
    {
        //reached end of tree
        if(root == NULL && subRoot == NULL)
        {
            return true;
        }

        //if either of the trees reaches end
        if(root == NULL || subRoot == NULL)
        {
            return false;
        }

        if(root->val != subRoot->val)
        {
            return false;
        }

        return(compareNodes(root->left, subRoot->left) && compareNodes(root->right, subRoot->right));
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(subRoot == NULL)
        {
            return true;
        }

        if(root == NULL)
        {
            return false;
        }

        //check if the two trees are same and return true
        if(compareNodes(root, subRoot))
        {
            return true;
        }

        //recursively make calls to left child of root node to check other subtrees
       bool left = isSubtree(root->left, subRoot);

        //recursively make calls to right child of root node to check other subtrees
        bool right = isSubtree(root->right, subRoot);

        //check if even either of the left or right subtree are same as subRoot in input
        return left || right;
    }
};
