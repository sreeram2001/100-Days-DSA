class Solution {
public:

    set<vector<int>> sett;
    void subset(vector<int>& nums, int ind, vector<int>& arr)
    {
        if(ind >= nums.size())
        {
            sett.insert(arr);
            return;
        }

        //to be included
        arr.push_back(nums[ind]);
        subset(nums, ind+1, arr);
        arr.pop_back();

        //not to be included
        subset(nums, ind+1, arr);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<int> arr;
        sort(nums.begin(), nums.end());
        subset(nums, 0, arr);
        vector<vector<int>> op;

        for(auto it : sett)
        {
            op.push_back(it);
        }

        return op;
    }
};
