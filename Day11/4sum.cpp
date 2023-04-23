class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> op;
        set<vector<int>> curr;      //to store unique 4sum arrays

        //if length is less than 4
        if(nums.size() < 4)
        {
            return op;
        }

        //sort the array
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-3;i++)
        {
            for(int j=i+1;j<nums.size()-2;j++)
            {
                int left = j+1;
                int right = nums.size()-1;

                //using two pointer approach
                while(left < right)
                {   
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target)
                    {
                        {
                            curr.insert({nums[i], nums[j], nums[left], nums[right]});
                        }
                        left++;
                        right--;
                    }
                    else if(sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }

        for(auto c:curr)
        {
            op.push_back(c);
        }
        return op;
    }
};
