class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        //STACK TO STORE THE ELEMENTS
        stack<int> histo;
        int i= 0;
        int maxArea = 0;
        int top, height, width;

        while( i < heights.size())
        {
            //if stack is empty or current element is greater than top of stack, push
            if(histo.empty() || heights[i] >= heights[histo.top()])
            {
                //we push the index of element into the stack
                histo.push(i);
                i++;
            }
            //if  in case element is lesser than the top, we will pop out the items from 
            //stack as it can not be extended or used anymore. we calculate maxArea so far
            else
            {
                top = histo.top();
                histo.pop();     //pop out the element

                height = heights[top];
                width = histo.empty()?i:i-histo.top()-1;
                maxArea = max(maxArea, height*width);
            }
        }

        //there are some left over items in the stack
        while(!histo.empty())
        {
            top = histo.top();
            histo.pop();     //pop out the element

            height = heights[top];
            width = histo.empty()?i:i-histo.top()-1;
            maxArea = max(maxArea, height*width);
        }

        return maxArea;
    }
};
