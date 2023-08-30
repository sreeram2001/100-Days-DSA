class Solution {
public: 
    void recurs(vector<int> &nums, vector<vector<int>> &op, vector<int> &curr,
     vector<int>& map, int ind)
    {
        //termination case
        if(nums.size() == curr.size())
        {
            op.push_back(curr);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(!map[i])
            {
                curr.push_back(nums[i]);
                map[i] = 1;
                recurs(nums, op, curr, map, ind);
                curr.pop_back();
                map[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> op;
        vector<int> curr;
        int n = nums.size();
        vector<int> map;
        for(int i=0;i<nums.size();i++)
        {
            map.push_back(0);
        }
        recurs(nums, op, curr, map, 0);
        return op;
    }
};
