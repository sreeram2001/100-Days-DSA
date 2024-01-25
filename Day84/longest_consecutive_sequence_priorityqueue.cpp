class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int maxi = 0;

        if(nums.size() < 1)
        {
            return 0;
        }
        
        //use a priority queue
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }

        int count = 1;  //counter
        int prev = pq.top();    //first element
        pq.pop();

        while(!pq.empty())
        {
            int curr = pq.top();
            pq.pop();

            if(curr != prev)
            {
                if(curr == prev+1)
                {
                    count++;
                }
                else
                {
                    count = 1;
                }
            }

            maxi = max(maxi, count);
            prev = curr;
        }

        maxi = max(maxi, count);
        return maxi;
    }
};
