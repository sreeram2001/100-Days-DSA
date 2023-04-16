class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxi = INT_MIN;
        int window = 0;

        //using kadane's algorithm
        for(int i=0;i<nums.size();i++)
        {
            window = window + nums[i];

            if(maxi <= window)
            {
                maxi = window;
            }

            //if current sum is negative make it 0
            if(window < 0)
            {
                window = 0;
            }
        }

        return maxi;
    }
};
