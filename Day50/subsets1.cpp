class Solution {
public:
    
    //have a set to eliminate the duplicate subsets
    set<vector<int>> st;

    void recursSubs(vector<int> nums, int ind, vector<int> curr)
    {
        if(ind >= nums.size())
        {
            st.insert(curr);
            return;
        }

        //include the element
        //append it to curr array
        curr.push_back(nums[ind]);
        recursSubs(nums, ind+1, curr);
        //remove it from curr array before next recursive so we don't extra elements
        curr.pop_back();

        //when element is not included
        recursSubs(nums, ind+1, curr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> op;     //the output array

        vector<int> curr;
        recursSubs(nums, 0, curr);

        for(auto it:st)
        {
            op.push_back(it);
        }

        return op;
    }
};
