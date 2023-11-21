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

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> op;
        queue<TreeNode*> q;

        if(root == NULL)
        {
            return op;
        }

        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int> lvl;

            for(int i=0;i<size;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                
                if(temp->left != NULL)
                {
                    q.push(temp->left);
                }
                if(temp->right != NULL)
                {
                    q.push(temp->right);
                }

                lvl.push_back(temp->val);
            }
            op.push_back(lvl);
        }

        reverse(op.begin(), op.end());
        return op;
    }
};
