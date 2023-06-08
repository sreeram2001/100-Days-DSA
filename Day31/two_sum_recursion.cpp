class Solution {
public:

    vector<int> op;

    vector<int> recur(vector<int> nums, int ele, int ind, int target)
    {
        if(ind == nums.size())
        {
            return op;
        }

        ele = nums[ind];

        for(int i=ind+1; i<nums.size(); i++)
        {
            if(ele + nums[ind] == target)
            {
                op.push_back(ind);
                op.push_back(i);
                return op;
            }
        }
        return recur(nums, ele, ind+1, target);
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        
        recur(nums, 0, 0, target);
        return op;
    }
};
