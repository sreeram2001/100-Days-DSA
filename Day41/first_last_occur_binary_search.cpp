class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int low = 0;
        int high = nums.size()-1;
        vector<int> op = {-1, -1};

        while(low <= high)
        {
            int mid = (low+high)/2;

            if(nums[mid] == target)
            {
                op[0] = mid;
                op[1] = mid;
                low = high = mid;
                
                //find leftmost starting point
                while(low > 0 && nums[low-1] == target)
                {
                    low--;
                }

                //find rightmost ending point
                while(high < nums.size()-1 && nums[high+1] == target)
                {
                    high++;
                }

                op[0] = low;
                op[1] = high;
                return op;
            }

            else if(nums[mid] < target)
            {
                low = mid+1;
            }

            else
            {
                high = mid-1;
            }
        }

        return op;
    }
};
