class Solution {
public:

    void recurs(vector<vector<int>> &op, vector<int> &nums, int ind)
    {  
        //base case- termination case
        if(ind == nums.size())
        {
            op.push_back(nums);
            return;
        }

        //run a for loop from current index to length of i/p array
        //swap each index to its all right indeces
        for(int i=ind;i<nums.size();i++)
        {
            //swap the index
            swap(nums[i], nums[ind]);
            //recursive call to next index
            recurs(op, nums, ind+1);
            //now we reswap so that we retain the i/p array for next recursive call
            swap(nums[i], nums[ind]);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> op;
        recurs(op, nums, 0);
        return op;
    }
};
