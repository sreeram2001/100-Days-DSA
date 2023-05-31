class Solution {
public:

    //declared globally as this is output array
    vector<vector<int>> op;

    //recursion solution
    void recurs(vector<int>& nums, int ind, int target,vector<int>& arr)
    {
        //when length has reached maximum index
        if(ind == nums.size())
        {
            return;
        }

        //when target value less than zero, return None
        if(target < 0)
        {
            return;
        }

        if(target == 0)
        {
            op.push_back(arr);
            return;
        }

        //now increment index
        recurs(nums, ind+1, target, arr);
        
        //now add element to array being at same index
        //same elements can be any times so
        if(nums[ind] <= target)
        {
            arr.push_back(nums[ind]);
            recurs(nums, ind, target - nums[ind], arr);
            arr.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> arr;
        recurs(candidates, 0, target, arr);
        return op;
    }
};
