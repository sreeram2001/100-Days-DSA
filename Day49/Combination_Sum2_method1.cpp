class Solution {
public:

    vector<vector<int>> v;
    set<vector<int>> st;

    void recursComb(vector<int> &curr, vector<int> candidates, int target, int sumi, int ind)
    {   
        //if recursion reaches the end, last index
        if(ind >= candidates.size())
        {
            if(sumi == target)
            {
                //if sumi has reached target value
                //we push it to output set to avoid duplicates set named st
                // v.push_back(curr);
                st.insert(curr);
            }
            return;
        }

        //include the element
        curr.push_back(candidates[ind]);
        //increment the sum
        sumi += candidates[ind];
        recursComb(curr, candidates, target, sumi, ind+1);
        //decrement the sum before next recursive call of not including the element
        //remove the element from the array as well
        sumi -= candidates[ind];
        curr.pop_back();

        //recursive calls for non-inclusion of the element
        recursComb(curr, candidates, target, sumi, ind+1);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

            sort(candidates.begin(), candidates.end()); //sort the input array
            vector<int> curr;
            recursComb(curr, candidates, target, 0, 0);
            
            for(auto it:st)
            {
                v.push_back(it);
            }
            return v;
    }
};
