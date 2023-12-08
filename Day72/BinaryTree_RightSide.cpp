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

    vector<int> op;

    void recurRight(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        //level order traversal
        while(!q.empty())
        {
            vector<int> lvl;
            int size = q.size();

            for(int i=0;i<size;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }

                lvl.push_back(temp->val);
            }

            op.push_back(lvl[lvl.size()-1]);
        }
    }

    vector<int> rightSideView(TreeNode* root) {

        recurRight(root);
        return op;
    }
};
