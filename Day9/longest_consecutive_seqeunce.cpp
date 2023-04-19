class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mp;

        //give 1 to every element
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]] = 1;
        }

        //now for every nums[i] if nums[i-1] prev item is present make nums[i] = 0
        //we make nums[i]=0, as it is not the starting point
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i]-1) != mp.end())
            {
                nums[i] = 0;
            }
        }

        //now we have every starting point elements
        //iterate through map and check if next element (consecutive) is present or not
        int maxi = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]] == 1)
            {
                int len = 0;
                int numi = nums[i];
                while(mp.find(numi) != mp.end())
                {
                    len++;
                    numi++;
                }
                maxi = max(maxi,len);
            }
        }
        return maxi;
    }
};
