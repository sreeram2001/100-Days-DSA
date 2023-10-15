class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        //sort the array
        sort(nums.begin(), nums.end());

        int n = nums.size();    //length of array

        //remove duplicates keeping only unique from nums
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        int changes = n;    //tracks number of changes to be made
        int mini, maxi;

        for(int i=0;i<nums.size();i++)
        {
            //for every index we create a window
            mini = nums[i];
            maxi = mini + n - 1;
            int count = 0;

            //iterate from 0th number check how many doesnot fall under range
            //these numbers needs to be changed
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j] < mini || nums[j] > maxi)
                {
                    count++;
                }
            }

            //track minimum changes to be made
            changes = min(changes, count);
        }

        //n - nums.size() gives us total duplicates
        changes = changes + (n-nums.size());
        return changes;
    }
};
