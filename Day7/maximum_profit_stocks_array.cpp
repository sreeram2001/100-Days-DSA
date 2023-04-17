class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int prof = 0;

        if(prices.size() == 1)
        {
            return 0;
        }

        if(prices.size() == 2 && prices[1] >= prices[0])
        {
            prof = prices[1] - prices[0];
            return prof;
        }

        //initialize
        int mini = prices[0];
        int maxi = INT_MIN;

        if(prices[1] > prices[0])
        {
            mini = prices[0];
            maxi = prices[1];
            prof = maxi - mini;
        }

        for(int i=1;i<prices.size();i++)
        {
            if(prices[i] > prices[i-1])
            {
                maxi = max(maxi, prices[i]);
                prof = max(prof, maxi-mini);
            }

            else if(prices[i] < mini)
            {
                mini = prices[i];
                maxi = prices[i];
            }
        }
        return prof;
    }
};
