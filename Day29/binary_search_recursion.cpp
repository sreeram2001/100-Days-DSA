class Solution {
public:

    int binary(vector<int> arr, int low, int high, int target)
    {
        if(low <= high)
        {
            int mid = (low+high)/2;

            //base condition
            if(arr[mid] == target)
            {
                return mid;
            }

            else if(arr[mid] < target)
            {
                return binary(arr, mid+1, high, target);
            }

            else
            {
            return binary(arr, low, mid-1, target);
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        
        int op = binary(nums, 0, nums.size()-1, target);
        return op;
    }
};
