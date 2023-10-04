class Solution {
public:

    //output array
    vector<vector<int>> op;

    void recursSub(vector<int>& nums, vector<int>& curr, int index)
    {
        //base case - termination
        if(nums.size() <= index)
        {
            op.push_back(curr);
            return;
        }

        //including the next element
        curr.push_back(nums[index]);        
        recursSub(nums, curr, index+1);
        curr.pop_back();

        //not including the next element
        recursSub(nums, curr, index+1);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> curr;
        recursSub(nums, curr, 0);
        return op;
    }
};
