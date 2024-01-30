class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> v;
        set<vector<int>> sett;
        int l = 0;
        int r = nums.size()-1;

        //sort the array for two pointer approach
        sort(nums.begin(), nums.end());

        for(int i=0;i<nums.size()-2;i++)
        {   
            //we will fix one number at index i and use two pointer approach with the other two numbers.
            l = i + 1;
            //fix the right pointer to the end for every iteration
            r = nums.size()-1;

            while(l < r)
            {   
                if(nums[i] + nums[l] + nums[r] == 0)
                {   
                    sett.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }

                //if sum is less than target, increase left pointer
                else if(nums[i] + nums[l] + nums[r] < 0)
                {
                    l++;
                }

                //if sum is greater than target, decrease the right pointer, decrement the value
                else if(nums[i] + nums[l] + nums[r] > 0)
                {
                    r--;
                }
            }
        }

        for(auto it:sett)
        {
            v.push_back(it);
        }
        return v;
    }
};
