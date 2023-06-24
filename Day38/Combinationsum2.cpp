class Solution {
public:

    void recurseComb(vector<int> nums, vector<vector<int>> &op, int ind, int target, vector<int> &curr)
    {
        //check if target is 0
        if(target == 0)
        {
            op.push_back(curr);
            return;
        }

        //include the element
        //we iterate from ind position to len(nums)
        for(int i=ind; i< nums.size(); i++)
        {
            //to stop avoiding duplicate combos
            if(i > ind && nums[i] == nums[i-1])
            {
                continue;
            }

            //we stop recursion if next element is greather than target
            if(nums[i] > target)
            {
                break;
            }

            if(target >= nums[ind])
            {
                curr.push_back(nums[i]);
                recurseComb(nums, op, i+1, target-nums[i], curr);
                //remove the element after call
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        //sort the input as we need sorted combinations
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> op;
        vector<int> curr;
        recurseComb(candidates, op, 0, target, curr);
        return op;
    }
};
