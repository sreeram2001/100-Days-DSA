class Solution {
public:
    vector<vector<int>> op;

    void recCombSum2(vector<int> candidates, vector<int>& curr, int target, int ind)
    {
        
        if(target == 0)
        {
            op.push_back(curr);
            return;
        }

        for(int i=ind;i<candidates.size();i++)
        {
            //if value goes more than target stop
            if(candidates[i] > target)
            {
                break;
            }

            //we check if current value is equal to the next upcoming value if so stop recursion
            //eliminate the duplicates
            if(i > ind && candidates[i] == candidates[i-1])
            {
                continue;
            }

            curr.push_back(candidates[i]);
            recCombSum2(candidates, curr, target - candidates[i], i+1);
            curr.pop_back();
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        recCombSum2(candidates, curr, target, 0);
        return op;
    }
};
