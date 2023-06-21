class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.size() == 1)
        {
            return nums.size();
        }

        int count = 0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i] != nums[i+1])
            {
                nums[count] = nums[i];
                count++;
            }
        }

        nums[count] = nums[nums.size()-1];
        count++;
        return count;
    }
};
