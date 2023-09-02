class Solution {
public:

    vector<string> op; //output array

    void recurs(int n, int open, int close, string s)
    {
        //base case
        //close is number of close brackets, similarily is open
        if(close == n)
        {
            op.push_back(s);
            return;
        }

        //add-openbracket case
        //when open brackets have reached limit we stop
        if(open < n)
        {
            s.push_back('(');
            recurs(n, open+1, close, s);
            s.pop_back();
        }

        //ADD-CLOSEBRACKET-CASE
        //if no open brackets then do not add close bracket
        if(open-close > 0)
        {
            s.push_back(')');
            recurs(n, open, close+1, s);
            s.pop_back();
        }
    }


    vector<string> generateParenthesis(int n) {
        
        recurs(n, 0, 0, "");
        return op;
    }
};
