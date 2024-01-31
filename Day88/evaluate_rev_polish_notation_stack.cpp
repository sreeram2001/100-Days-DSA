class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int op = 0;
        //stack to store the numbers
        stack<int> stac;

        for(int i=0;i<tokens.size();i++)
        {
            if(stac.size() > 1 && tokens[i] == "/")
            {
                int n1 = stac.top();
                stac.pop();
                int n2 = stac.top();
                stac.pop();
                op = n2/n1;
                stac.push(op);
            }
            else if(stac.size() > 1 && tokens[i] == "*")
            {
                int n1 = stac.top();
                stac.pop();
                int n2 = stac.top();
                stac.pop();
                op = n1*n2;
                stac.push(op);
            }
            else if(stac.size() > 1 && tokens[i] == "-")
            {
                int n1 = stac.top();
                stac.pop();
                int n2 = stac.top();
                stac.pop();
                op = n2 - n1;
                stac.push(op);
            }
            else if(stac.size() > 1 && tokens[i] == "+")
            {
                int n1 = stac.top();
                stac.pop();
                int n2 = stac.top();
                stac.pop();
                op = n2 + n1;
                stac.push(op);
            }
            else
            {
                stac.push(stoi(tokens[i]));
            }
        }
        return stac.top();
    }
};
