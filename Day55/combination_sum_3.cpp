class Solution {
public:
    void recurs(vector<vector<int>>& op, vector<int> nums, vector<int>& curr, int ind, int target, int k)
    {
        //base case
        if(ind == nums.size())
        {
            //we need only k numbers
            if(target ==0 && curr.size() == k)
            {
                op.push_back(curr);
            }    
            return;    
        }

        //include case
        curr.push_back(nums[ind]);
        recurs(op, nums, curr, ind+1, target - nums[ind], k);
        curr.pop_back();

        //not include case
        recurs(op, nums, curr, ind+1, target, k);
    }


    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> op; //output array
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<int> curr;   //to hold current running recursion values of nums array

        if(n < k)
        {
            return op;
        }
        
        recurs(op, nums, curr, 0, n, k);
        return op;
    }
};
