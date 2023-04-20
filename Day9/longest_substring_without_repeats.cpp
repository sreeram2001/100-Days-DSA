class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        map<char, int> visited;
        int l=0,output=0;

        for(int r=0;r<s.size();r++)
        {
            //if item is already visited
            if(visited.find(s[r]) != visited.end())
            {
                //if item not in current window increment right pointer
                if(visited[s[r]] < l)
                {
                    output = max(output, r-l+1);
                }
                //if item in curr window, increment left to next position of item
                else
                {
                    l = visited[s[r]]+1;
                }
            }

            //if item not yet visited increment right pointer
            else
            {
            output = max(output, r-l+1);
            }
            
            visited[s[r]] = r;
        }

        return output;
    }
};
