class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.size() < t.size())
        {
            return "";
        }

        unordered_map<char, int> mp;
        int minLen = INT_MAX, count = 0, start = 0, winstart = 0;

        //let us fill up freqeuency of characters of string t
        for(int i=0;i<t.size();i++)
        {
            mp[t[i]]++;
        }

        //end is used to iterate thru string s
        //end will give us ending position of window
        for(int end = 0; end<s.size(); end++)
        {   
            //if any char of t is present in s then increment count
            if(mp[s[end]] > 0)
            {
                count++;
            }

            //decrement the freqeuncy from map of curr element
            mp[s[end]]--;

            //if count equal to length then we got our window
            //window contains all elements present in t
            if(count == t.size())
            {
                //we move start position as long as we don't need
                //unnecessary elements which are not part of String "t"
                //char with freq value -1 and so on less than 0 is not needed
                while( start < end && mp[s[start]] < 0)
                {
                    mp[s[start]]++;
                    start++;
                }

                //we calculate the size of window
                if(minLen > (end - start))
                {
                    winstart = start;
                    minLen = end - start + 1;
                }

                //now increment the frequency of start element
                mp[s[start]]++;
                start++;
                count--;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(winstart, minLen) ;

    }
};
