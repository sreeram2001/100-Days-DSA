class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        n = len(heights)
        ans = 0

        for i in range(0,n+1):

            while(stack and (i==n or heights[stack[-1]] >= heights[i])):
                h = heights[stack[-1]]
                stack.pop()

                if(stack):
                    w = i - stack[-1] - 1
                else:
                    w = i

                ans = max(ans, w*h)
            stack.append(i)
        
        return ans

        
