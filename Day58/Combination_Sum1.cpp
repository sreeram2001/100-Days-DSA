class Solution {
public:
    vector<vector<int>> op;

    void recCombDup(vector<int> candidates, vector<int> curr, int target, int index)
    {   
        //base - case - termination case
        if(index >= candidates.size() || target < 0)
        {
            return;
        }

        if(target == 0)
        {
            op.push_back(curr);
            return;
        }

        //include the current element until target is not exceeded
        if(candidates[index] <= target)
        {
            curr.push_back(candidates[index]);
            recCombDup(candidates, curr, target - candidates[index], index);
            curr.pop_back();
        }

        //moving with next element
        recCombDup(candidates, curr, target, index+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> curr;
        recCombDup(candidates, curr, target, 0);
        return op;
    }
};
