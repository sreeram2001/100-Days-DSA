class Solution {
public:

    int minOperations(vector<int>& nums) {

        int change= 0;  //number of changes tobe made
        //first sort the array
        sort(nums.begin(), nums.end());

        //min element is frst element
        int mini = nums[0];
        //maxi element is 
        int maxi = mini + nums.size() - 1;

        //we run a loop from (min, max) range to check how many no.s are present
        for(int i=mini;i<=maxi;i++)
        {
            //if number is not present then count it as changable
            if(!count(nums.begin(), nums.end(), i))
            {
                change++;
            }
        }

        return change;
    }
};
