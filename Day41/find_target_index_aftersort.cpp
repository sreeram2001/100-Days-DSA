class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {

        int lessthan = 0, count = 0;
        vector<int> op;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] < target)
            {
                lessthan++;
            }

            else if(nums[i] == target)
            {
                count++;
            }
        }

        while(count)
        {
            op.push_back(lessthan);
            lessthan++;
            count--;
        }

        return op;
        
    }
};
