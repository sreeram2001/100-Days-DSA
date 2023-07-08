class Solution {
public:

    vector<vector<int>> op;

    //function to create subarrays
    void recurseSub(vector<int> nums, int target, int start, int end)
    {
        //terminate condition
        if(end == nums.size())
        {
            return;
        }

        //if start reaches end value, recursive call
        //increment end to next place
        else if(start > end)
        {
            recurseSub(nums, target, 0, end+1);
        }

        //creating subarray
        else
        {
            vector<int> curr;
            int cnt = 0;

            for(int i=start;i<=end;i++)
            {
                curr.push_back(nums[i]);
                cnt = cnt + nums[i];
            }
            if(cnt >= target)
            {
                op.push_back(curr);
            }

            recurseSub(nums, target, start+1, end);
        }
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        
        recurseSub(nums, target, 0, 0);
        int mini = INT_MAX;

        for(int i=0;i<op.size();i++)
        {
            int l = op[i].size();
            mini = min(mini, l);
        }

        return (mini == INT_MAX ? 0 : mini);
    }
};
