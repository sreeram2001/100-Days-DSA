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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> op;
        if(root == NULL)
        {
            return op;
        }

        queue<TreeNode*> q;
        q.push(root);
        int size;

        while(!q.empty())
        {
            vector<int> level;    //array to 
            size = q.size();        //update size of queue

            for(int i=0;i<size;i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if(node->left != NULL)
                {
                    q.push(node->left);
                }
                if(node->right != NULL)
                {
                    q.push(node->right);
                }

                level.push_back(node->val);
            }
            
            op.push_back(level);
        }

        return op;
    }
};
