class Solution {
public:
    //output vector
    vector<vector<int>> op;

    void recursCombSum2(vector<int> candidates, int ind, int target, vector<int>& curr)
    {
        if(target == 0)
        {
            op.push_back(curr);
            return;
        }

        for(int i=ind;i<candidates.size();i++)
        {   

            //if value goes more than target, come out of loop
            if(candidates[i] > target)
            {
                break;
            }

            //we check if current value is equal to the next upcoming value if so we don't recursion for it
            //this is done in order to eliminate the duplicates cases aka combinations
            if(i > ind && candidates[i] == candidates[i-1])
            {
                continue;
            }

            curr.push_back(candidates[i]);
            recursCombSum2(candidates, i+1, target - candidates[i], curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        //sort the input array
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        recursCombSum2(candidates, 0, target, curr);
        return op;
    }
};
