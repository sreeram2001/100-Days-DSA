class Solution {
public:

    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int mid;
        vector<int> op = {-1, -1};

        while(low <= high)
        {
            mid = (low+high)/2;

            if(nums[mid] == target)
            {
                int left = mid;
                while(left > 0 && nums[left-1] == target)
                {
                    left--;
                }

                int right = mid;
                while(right < nums.size()-1 && nums[right+1]==target)
                {
                    right++;
                }

                op[0] = left;
                op[1] = right;
                return op;
            }
            else if(target > nums[mid])
            {
                low = mid+1;
            }
            else if(target < nums[mid])
            {
                high = mid-1;
            }

        }

        return op;
    }
};
