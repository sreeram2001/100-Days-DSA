class Solution {
public:

    //output vector array
    vector<vector<string>> op;

    void recurs(vector<string> &nums, int ind)
    {
        if(ind == nums.size())
        {
            op.push_back(nums);
            for(auto it:nums)
            {
                std::cout<<it;
            }
            return;
        }

        for(int i=ind;i<nums.size();i++)
        {
            //swap
            swap(nums[i], nums[ind]);
            recurs(nums, ind+1);
            //reswap
            swap(nums[i], nums[ind]);
        }
    }

    string getPermutation(int n, int k) {
        
        // string nums;
        vector<string> nums;
        for(int i=1;i<n+1;i++)
        {
            nums.push_back(to_string(i));
        }
        string output;
        recurs(nums, 0);

        for(int i=0;i<op[k-1].size();i++)
        {
            output += op[k-1][i];
        }

        return output;

    }
};
