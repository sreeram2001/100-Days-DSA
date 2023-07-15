class Solution {
public:

    bool recurse(string s, int l, int r)
    {
        if(l >= r)
        {
            return true;
        }

        if(s[l] != s[r])
        {
            return false;
        }

        return recurse(s,l+1, r-1);
    }

    bool isPalindrome(string s) {
        
        string ss = "";
        for(int i=0;i<s.size();i++)
        {
            if(s[i] != ' ')
            {
                //97-122
                //65-90
                //48-57
                if( (int(s[i]) >= 48 && int(s[i])<=57) || (int(s[i]) >= 97 && int(s[i])<=122) || (int(s[i]) >= 65 && int(s[i])<=90)) 
                {
                    ss = ss + (char)tolower(s[i]);
                }
            }
        }
        
        return recurse(ss, 0 , ss.size()-1);
        
    }
};
