class Solution {
public:

    void recursPermu(vector<vector<int>>& op, vector<int>& curr, vector<int> nums, map<int, int>& freq)
    {
        if(curr.size() == nums.size())
        {
            op.push_back(curr);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(!freq[nums[i]])
            {
                freq[nums[i]]++;
                curr.push_back(nums[i]);
                recursPermu(op, curr, nums, freq);
                curr.pop_back();
                freq[nums[i]]--;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> op;
        vector<int> curr;
        map<int, int> freq;

        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]] = 0;
        }

        recursPermu(op, curr, nums,freq);
        return op;
    }
};
