class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int mini = INT_MAX;
        int wind = 0;
        int end=0;

        for(int i=0;i<nums.size();i++)
        {
            wind = nums[i];
            end = i;

            while(wind < target && end < nums.size()-1)
            {
                end++;
                wind = wind + nums[end];
            }

            if(wind >= target)
            {
                mini = min(end-i+1, mini);
            }
        }

        if(mini == INT_MAX)
        {
            return 0;
        }

        return mini;
    }
};
