class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.empty())
        {
            return 0;
        }

        int outp = 0;
        int size = height.size();
        vector<int> dp_left(size);     //to calculate max height in left side of each element
        vector<int> dp_right(size);    //to calculate max height in right side of each element

        dp_left[0] = height[0];
        dp_right[size-1] = height[size-1];

        //find max height in left side of element, traverse front to right end
        for(int i=1;i<size;i++)
        {
            dp_left[i] = max(dp_left[i-1], height[i]);
        }

        //find max height in right side of element, traverse back to left end
        for(int i=size-2;i>=0;i--)
        {
            dp_right[i] = max(dp_right[i+1], height[i]);
        }

        //now get min of left, right max end element and subtract with current height
        for(int i=1;i<size-1;i++)
        {
            outp = outp + (min(dp_left[i], dp_right[i]) - height[i]);
        }

        return outp;
    }
};
