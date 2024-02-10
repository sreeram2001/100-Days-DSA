class Solution {
public:
    int search(vector<int>& nums, int target) {

        int high = nums.size()-1;
        int low = 0;
        
        while(low <= high)
        {
            int mid = (low+high)/2;

            //if target is reached return index
            if(nums[mid] == target)
            {
                return true;
            }

            //to check for duplicates
            if(nums[low] == nums[mid] && nums[high] == nums[mid])
            {
                low++;
                high--;
            }
            //to check if left side of mid is sorted
            else if(nums[low] <= nums[mid])
            {
                //check if target lies within low and mid
                if(nums[low] <= target && target < nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            //check if right side of mid is sorted
            else
            {
                //check if target lies within mid and high
                if(nums[mid] < target && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};
