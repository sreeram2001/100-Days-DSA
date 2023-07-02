class Solution {
public:

    vector<int> op = {-1, -1};

    vector<int> recurse(vector<int> nums, int target, int ind)
    {
        if(ind == nums.size())
        {
            return op;
        }

        if(nums[ind] == target)
        {
            if(op[0] == -1)
            {
                op[0] = ind;
                op[1] = ind;
            }
            else
            {
                op[1] = ind;
            }
        }
        return recurse(nums, target, ind+1);
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        
        return recurse(nums, target, 0);
    }
};
