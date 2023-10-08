class Solution {
public:
    vector<vector<int>> op;

    void recursPerm(vector<int>& nums, int ind)
    {
        if(ind >= nums.size())
        {
            op.push_back(nums);
            return;
        }

        //iterate thru ind->arr.size and swap each item and recurse
        for(int i=ind;i<nums.size();i++)
        {
            swap(nums[ind], nums[i]);
            recursPerm(nums, ind+1);
            swap(nums[ind], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        recursPerm(nums, 0);
        return op;
    }
};
