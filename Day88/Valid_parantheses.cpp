class Solution {
public:

    bool isValid(string s) {
        
        //stack to store
        stack<char> stac;

        for(int i=0;i<s.size();i++)
        {
            //if stack is empty with no opening brackets and only closed brackets are left return false
            if(stac.empty() && (s[i]==')' || s[i] == '}' || s[i] == ']') ) 
            {
                return false;
            }
            else if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                stac.push(s[i]);
            }
            else if(s[i] == ')' && !stac.empty())
            {
                char curr = stac.top();
                stac.pop();
                //if opening and closing brackets do not match
                if(curr != '(')
                {
                    return false;
                }
            }
            else if(s[i] == ']' && !stac.empty())
            {
                char curr = stac.top();
                stac.pop();
                //if opening and closing brackets do not match
                if(curr != '[')
                {
                    return false;
                }
            }
            else if(s[i] == '}' && !stac.empty())
            {
                char curr = stac.top();
                stac.pop();
                //if opening and closing brackets do not match
                if(curr != '{')
                {
                    return false;
                }
            }
        }

        if(!stac.empty())
        {
            return false;
        }
        return true;
    }
};
