class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int zero,one,two;
        
        zero = count(nums.begin(),nums.end(),0);
        one = count(nums.begin(),nums.end(),1);
        two = count(nums.begin(),nums.end(),2);
        
        for(int i=0;i<nums.size();i++)
        {
            if(i<zero)
            {
                nums[i] = 0;
            }
            
            else if(i<zero+one)
            {
                nums[i] = 1;
            }
            
            else
            {
                nums[i] = 2;
            }
        }
    }
};
