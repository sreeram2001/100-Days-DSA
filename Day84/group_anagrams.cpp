class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string, vector<string>> mp;
        vector<vector<string>> op;

        //filling the frequency map
        for(int i=0;i<strs.size();i++)
        {
            string sorti = strs[i];
            sort(sorti.begin(), sorti.end());

            if(mp.contains(sorti))
            {
                mp[sorti].push_back(strs[i]);
            }
            else
            {   
                mp[sorti] = {strs[i]};
            }
        }

        for(auto it:mp)
        {
            op.push_back(it.second);
        }

        return op;
    }


};
