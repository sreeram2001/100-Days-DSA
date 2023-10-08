class Solution {
public:
    vector<vector<string>> op;

    void PalinPart(vector<string>& curr, int ind, string s)
    {
        if(ind == s.size())
        {
            op.push_back(curr);
            return;
        }

        for(int i=ind;i<s.size();i++)
        {
            if(isPalindromeSub(s,ind,i))
            {
                curr.push_back(s.substr(ind, i - ind + 1));
                PalinPart(curr, i+1, s);
                curr.pop_back();
            }
        }
    }

    bool isPalindromeSub(string s, int ind, int i)
    {
        if(ind >= i)
        {
            return true;
        }
        if(s[i] != s[ind])
        {
            return false;
        }
        return isPalindromeSub(s, ind+1, i-1);
    }

    vector<vector<string>> partition(string s) {
        vector<string> curr;
        PalinPart(curr, 0, s);
        return op;
    }
};
