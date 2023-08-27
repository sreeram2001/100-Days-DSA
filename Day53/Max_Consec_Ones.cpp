class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //using sliding window approach

        int start = 0;      //left/start pointer
        int maxi = 0;       //maximum length of window
        int cnt_zero = k;   //counter value to k

        //iterate the right/end pointer thru the loop
        for(int end=0;end<nums.size();end++)
        {
            //if curr value is 0, reduce cnt_zero size/k value
            if(nums[end] == 0)
            {
                cnt_zero--;
            }

            //if we happen to have maximum zeroes in window
            //i.e. k become zero in our case cnt_zero becomes zero
            //we shrink the window-size, so increase the start pointer
            if(cnt_zero < 0)
            {
                //we keep increasing left/start pointer of window
                //until we reach another '0', so as to make sure only k zeroes are present in window
                if(nums[start] == 0)
                {
                    cnt_zero++;
                }

                start++;
            }

            maxi = max(maxi, end-start+1);
        }
        
        return maxi; 
    }
};
