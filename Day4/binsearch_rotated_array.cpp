class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low =0, high = nums.size()-1;

        //binary search
        while(low <= high)
        {
            int mid = (low+high)/2;

            //if mid is target return the index
            if(nums[mid] == target)
            {
                return mid;
            }

            //check if left half is sorted
            if(nums[low] <= nums[mid])
            {
                //apply binary search to left half
                if(target < nums[mid] && target >= nums[low])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }

            //check if right half is sorted
            else
            {
                //apply binary search to right half
                if(target > nums[mid] && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
