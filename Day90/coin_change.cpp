class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        //2d array dp [ coins in rows], amount target in cols
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0) );

        //initialise top column
        for(int j=0;j<1+amount;j++)
        {
            dp[0][j] = 1000000;
        }

        for(int i=1;i<coins.size()+1;i++)
        {
            for(int j=1;j<1+amount;j++)
            {   
                //only if current amount is reachable or greater than the coin update dp
                if(j >= coins[i-1])
                {   
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i][j - coins[i-1]]);
                }
                //else update with top or previous dp coin value
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        //in case dp val goes above amount return not possible
        if(dp[coins.size()][amount] >= 1+amount)
        {
            return -1;
        }
        //else return the total number of coins taken to reach target
        else
        {
            return dp[coins.size()][amount];
        }
    }
};
