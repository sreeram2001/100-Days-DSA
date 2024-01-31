class Solution {
public:

    //output array
    vector<string> op;

    void generate(int n, int open, int close, string s)
    {
        //base case
        if(close == n)
        {
            op.push_back(s);
            return;
        }

        //push open brackets until it reaches n
        if(open < n)
        {
            s.push_back('(');
            generate(n, open+1, close, s);
            s.pop_back();
        }

        if(open > close)
        {
            s.push_back(')');
            generate(n, open, close+1, s);
            s.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        generate(n, 0, 0, "");
        return op;
    }
};
