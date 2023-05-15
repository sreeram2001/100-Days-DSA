class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> stac;
        
        for(int i=0;i<path.size();i++)
        {   
            //skip if its "/"
            if(path[i] == '/')
            {
                continue;
            }

            //now iterate and add to string temp until its not "/"
            string temp;

            while(i < path.size() && path[i] != '/')
            {
                temp = temp + path[i];
                i++;
            }

            if(temp == ".")
            {
                continue;
            }

            else if(temp == "..")
            {
                if(!stac.empty())
                {
                    stac.pop();
                }
            }

            else
            {
                stac.push(temp);
            }

        }


        //add all stack items to output string
        string op;

        while(!stac.empty())
        {
            op = "/" + stac.top() + op;
            stac.pop();
        }

        if(op.size() == 0)
        {
            return "/";
        }

        return op;

    }
};
