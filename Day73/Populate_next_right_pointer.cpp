/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:

    Node* connect(Node* root) {

        if(root == NULL)
        {
            return root;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            vector<Node*> lvl;
            int size = q.size();

            for(int i=0;i<size;i++)
            {
                Node* top = q.front();
                q.pop();

                if(top->left != NULL)
                {
                    q.push(top->left);
                }
                if(top->right != NULL)
                {
                    q.push(top->right);
                }
                lvl.push_back(top);
            }

            for(int i=0;i<size-1;i++)
            {
                lvl[i]->next = lvl[i+1];
            }
            lvl[lvl.size()-1]->next = NULL;
        }

        return root;
    }
};
