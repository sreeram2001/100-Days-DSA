class Solution {
public:

    int binarySearch(vector<int> nums, int low, int high, int target)
    {
        
        if(low <= high)
        {
            int mid = (low+high)/2;

            //base - condition aka termination condition 
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(target > nums[mid])
            {
                return binarySearch(nums, mid+1, high, target);
            }
            else if(target < nums[mid])
            {
                return binarySearch(nums, low, mid-1, target);
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        //calling recursive function
        return binarySearch(nums, 0, nums.size()-1, target);
    }
};
