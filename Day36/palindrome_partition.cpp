class Solution {
public:

    vector<vector<string>> partition(string s) {

        vector<vector<string>> op;
        vector<string> curr;
        recurse(s, op, 0, curr);
        return op;
    }

    void recurse(string s, vector<vector<string>> &op, int ind, vector<string> &curr)
    {
        if(ind == s.size())
        {
            op.push_back(curr);
            return;
        }

        for(int i=ind; i<s.size(); i++)
        {
            if(isPalindrome(s, ind, i))
            {
                curr.push_back(s.substr(ind, i - ind + 1));
                //recursive call
                recurse(s, op, i+1, curr);
                curr.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int left, int right)
    {
        while(left <= right)
        {
            if(s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
