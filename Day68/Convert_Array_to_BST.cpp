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

    TreeNode* insertBST(TreeNode* root, int num)
    {
        if(root == NULL)
        {
            root = new TreeNode(num);
            return root;
        }

        else
        {   
            
            if(root->val == num)
            {
                return root;
            }
            //insert into left child
            if(num < root->val)
            {
                root->left = insertBST(root->left, num);
            }
            //insert into right child
            if(num > root->val)
            {
                root->right = insertBST(root->right, num);
            }
        }
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        TreeNode* root = new TreeNode(nums[nums.size()/2]);
        for(int i=0;i<nums.size();i++)
        {
            root = insertBST(root, nums[i]);
        }
        return root;
    }
};
