class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        //dp array which stores maximum longest sequence so far
        vector<int> dp(nums.size(),1);

        //iterate thru elements of input array
        for(int i=0;i<nums.size();i++)
        {
            //now iterate from 0->current element 
            for(int j=0;j<i;j++)
            {
                //if element is less than the current element compute value
                if(nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
        }

        int maxi = *max_element(dp.begin(), dp.end());
        return maxi;
    }
};
