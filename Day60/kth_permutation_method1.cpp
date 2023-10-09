class Solution {
public:
    vector<string> op;

    void recursPerm(string& nums, int ind)
    {
        if(ind == nums.size())
        {
            op.push_back(nums);
            return;
        }

        for(int i=ind;i<nums.size();i++)
        {
            swap(nums[i], nums[ind]);
            recursPerm(nums, ind+1);
            swap(nums[i], nums[ind]);
        }
    }

    string getPermutation(int n, int k) {
        
        string nums = "";
        for(int i=1;i<=n;i++)
        {
            nums += to_string(i);
        }
        recursPerm(nums, 0);
        sort(op.begin(), op.end());
        return op[k-1];
    }
};
