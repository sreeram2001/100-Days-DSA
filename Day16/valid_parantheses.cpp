class Solution {
public:
    bool isValid(string s) {
        
        stack<char> stac;

        for(auto i:s)
        {
            if(stac.size()==0 && (i==')' || i==']' || i=='}'))
            {
                return false;
            }

            else if(i == '(' || i == '{' || i=='[')
            {
                stac.push(i);
            }

            else if(i == ')' && stac.size() > 0)
            {
                char popp = stac.top();
                stac.pop();
                if(popp != '(')
                {
                    return false;
                }
            }

            else if(i == ']' && stac.size() > 0)
            {
                char popp = stac.top();
                stac.pop();
                if(popp != '[')
                {
                    return false;
                }
            }

            else if(i == '}' && stac.size() > 0)
            {
                char popp = stac.top();
                stac.pop();
                if(popp != '{')
                {
                    return false;
                }
            }
        }

        if(stac.size() > 0)
        {
            return false;
        }
        return true;
        }
};
