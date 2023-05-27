class Solution {
public:
    vector<int>a = {-1, -1};

    void recursiveSearch(vector<int> nums, int ind, int tar)
    {
        if(ind >= nums.size())
        {
            return;
        }

        if(nums[ind] == tar)
        {
            if(a[0] == -1)
            {
                a[0] = ind;
                a[1] = ind;
            }
            else
            {
                a[1] = ind;
            }
        }

        recursiveSearch(nums,ind+1,tar);
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        recursiveSearch(nums, 0, target);
        return a;
    }
};
