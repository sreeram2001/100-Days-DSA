class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int window = 0, start = 0, mini = INT_MAX;

        for(int i=0;i<nums.size();i++)
        {
            window += nums[i];

            while(window >= target)
            {
                mini = min(mini, i-start+1);
                window -= nums[start];
                start += 1;
            }
        }

        return (mini==INT_MAX ? 0 : mini);
    }
};
