class Solution {
public:

    void recurs(string s, vector<vector<string>>& op, vector<string>& curr, int ind)
    {
        if(ind == s.size())
        {   
            op.push_back(curr);
            return;
        }

        for(int i=ind;i<s.size();i++)
        {
            if(palindromeCheck(s, ind, i))
            {
                curr.push_back(s.substr(ind, i-ind+1));
                recurs(s, op, curr, i+1);
                curr.pop_back();
            }
        }
    }

    //helper func to check if substrings are palindrome
    bool palindromeCheck(string s, int l, int r)
    {
        if(l >= r)
        {
            return true;
        }
        if(s[l] != s[r])
        {
            return false;
        }
        return palindromeCheck(s, l+1, r-1);
    }


    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> op; //output array
        vector<string> curr;    //holds currrent recursion values
        recurs(s, op, curr, 0);
        return op;
    }
};
