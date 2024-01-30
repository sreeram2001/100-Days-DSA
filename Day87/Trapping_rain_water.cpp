class Solution {
public:
    int trap(vector<int>& height) {
        
        int length = height.size();
        int totalvol = 0;   //variable to calculate total water capacity

        //if input array is empty
        if(height.empty())
        {
            return 0;
        }

        vector<int> maxleft(length, 0);
        vector<int> maxright(length, 0);
        int maxi = 0;

        //calculating the maximum value until left of current element to get left boundary
        for(int i=0;i<length;i++)
        {
            maxi = max(maxi, height[i]);    //get current maximum
            maxleft[i] = maxi;
        }

        //calculating the maximum value to right of current element to get right boundary
        maxi = 0;
        for(int i=length-1;i>=0;i--)
        {
            maxi = max(maxi, height[i]);
            maxright[i] = maxi;
        }

        //to get boundary, we take minimum value of left and right maxval of a current element
        for(int i=0;i<length;i++)
        {
            //sum the total container volume
            //total water capacity is boundary - height of each pipe
            totalvol += min(maxleft[i], maxright[i]) - height[i];
        }

        return totalvol;
    }
};
