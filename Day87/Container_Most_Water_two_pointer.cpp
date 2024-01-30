class Solution {
public:
    int maxArea(vector<int>& height) {

        int maxArea = 0;
        //two pointer
        int l = 0;
        int r = height.size()-1;

        while(l<=r)
        {   
            maxArea = max(maxArea, (r-l)*min(height[r], height[l]));
            if(height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }

        return maxArea;
    }
};
