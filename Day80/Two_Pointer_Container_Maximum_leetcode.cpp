class Solution {
public:
    int maxArea(vector<int>& height) {
        
        //two pointers
        int l = 0;
        int r = height.size()-1;
        
        int maxi = 0;       //stores maximum container value
        int curr = 0;

        while(l < r)
        {
            //calculating curr Area of Container - distance between pipe * height of pipes
            curr = (r-l)*min(height[l], height[r]);

            //compute the maximum area
            maxi = max(maxi, curr);
            
            //if the height of one pipe is lesser than the other increment, vice versa
            if(height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }

        return maxi;
    }
};
