class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        double wind = 0;
        double avg = 0;
        double max_avg = 0;

        for(int i=0;i<k;i++)
        {
            wind = wind + nums[i];
        }

        avg = wind/k;
        max_avg = avg;

        for(int i=k;i<nums.size();i++)
        {
            wind = wind - nums[i-k] + nums[i];
            avg = wind/k;

            if(max_avg <= avg)
            {
                max_avg = avg;
            }
        }
        
        return max_avg;
    }
};
