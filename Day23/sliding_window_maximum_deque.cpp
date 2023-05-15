class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> outp;
        deque<int> dq;          //using deque

        for(int i=0;i<nums.size();i++)
        {
            
            //remove smaller elements then current element from queue
            while(!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }

            //we push the index instead of element
            dq.push_back(i);

            //if elements outside window is present remove it from front
            if(dq.front() == i-k)
            {
                dq.pop_front();
            }

            //if window level of k reached, you can push the elements to outputlist
            if(i >= k-1)
            {
                outp.push_back(nums[dq.front()]);
            }

        }

        return outp;
        
    }
};
