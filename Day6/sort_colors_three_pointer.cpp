class Solution {
public:
    void sortColors(vector<int>& nums) {

        int start=0, end=nums.size()-1;
        int i=0;  //iterates through the array

        //three pointer method
        while(i <= end)
        {   
            //middle element is 1, swap values less than 1 to left of it
            if(nums[i] < 1)
            {
                swap(nums[i], nums[start]);
                start++;
                i++;
            }

            else if(nums[i] > 1)
            {
                swap(nums[i],nums[end]);
                end--;
            }

            else
            {
                i++;
            }
        }
    }
};
