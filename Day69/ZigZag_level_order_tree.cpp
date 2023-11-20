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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> op;       //stores the output
        if(root == NULL) return op;

        queue<TreeNode*> q;             //q used for bfs
        bool isZigZag = false;
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

                //if zigzag is true then push at front, reverse way
                if(isZigZag)
                {
                    lvl.insert(lvl.begin(),temp->val);
                }
                else
                {
                    lvl.push_back(temp->val);
                }
            }

            //reset zigzag value
            // isZigZag = (isZigZag == true) ? false : true;
            isZigZag = !isZigZag;
            op.push_back(lvl);
        }
        
        return op;
    }
};
