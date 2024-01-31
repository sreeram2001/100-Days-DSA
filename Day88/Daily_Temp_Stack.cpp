class Solution {
public:

    vector<int> dailyTemperatures(vector<int>& temperatures) {

        //stack to store indices
        stack<int> ind;
        int n =temperatures.size();
        vector<int> ans(n, 0);

        for(int i=0;i<n;i++)
        {   
            while(!ind.empty() && temperatures[i] > temperatures[ind.top()])
            {
                ans[ind.top()] = i - ind.top();
                ind.pop();
            }

            ind.push(i);
        }

        return ans;
    }
};
