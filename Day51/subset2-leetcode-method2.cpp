class Solution {
public:

    void SubsRecurs(vector<vector<int>> &op, vector<int> nums, int ind, vector<int> &curr)
    {

        op.push_back(curr);

        for(int i=ind; i<nums.size(); i++)
        {
            if(i != ind && (nums[i] == nums[i-1]))
            {
                continue;
            }

            curr.push_back(nums[i]);
            SubsRecurs(op, nums, i+1, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<vector<int>> op;
        SubsRecurs(op, nums, 0, curr);
        return op;
    }
};
