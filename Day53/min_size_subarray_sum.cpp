class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int mini = INT_MAX;
        int wind = 0;
        int start=0;

        for(int i=0;i<nums.size();i++)
        {
            wind += nums[i];

            //when window becomes greater than target
            //keep removing values from left end of window
            //calculate the min size
            while(wind >= target)
            {
                mini = min(mini,i-start+1);
                wind = wind - nums[start];
                start++;
            }
        }

        return (mini==INT_MAX ? 0 : mini);
    }
};
