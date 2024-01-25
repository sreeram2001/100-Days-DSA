class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int> mp;
        //using a priority queue
        priority_queue<pair<int, int>> pq;
        vector<int> op;

        //pushing items inside frequency map
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }

        //pushing inside priority queue
        for(auto it:mp)
        {
            pq.push({it.second, it.first});
        }

        //k most frequent elements
        while(k > 0 && !pq.empty())
        {
            op.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return op;
    }
};
