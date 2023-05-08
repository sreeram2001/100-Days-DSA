class Solution {
public:
    string reverseParentheses(string s) {

        stack<char> stac;
        queue<char> q;

        for(int i=0;i<s.size();i++)
        {
            if(s[i] != ')')
            {
                stac.push(s[i]);
            }
            else
            {
                while(stac.top() != '(')
                {
                    q.push(stac.top());
                    stac.pop();
                }

                //remove the extra '(' open bracket from stack
                stac.pop();

                //now push the elements in queue back to stack
                while(!q.empty())
                {
                    stac.push(q.front());
                    q.pop();
                }
            }

        }

        string op = "";
        while(!stac.empty())
        {
            op = stac.top() + op;
            stac.pop();
        }

        return op;
    }
};
