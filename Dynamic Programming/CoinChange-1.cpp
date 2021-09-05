//https://leetcode.com/problems/coin-change/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if(i==0&&j==0)
                {
                    dp[i][j]=0;
                    continue;
                }
                
                if(i==0)
                {
                    dp[i][j]=1e9;
                    continue;
                }
                
                if(j==0)
                {
                    dp[i][j]=0;
                    continue;
                }

                int inc;
                if(coins[i-1]>j)
                    inc=1e9;
                else
                    inc=1+dp[i][j-coins[i-1]];
                
                int exc=dp[i-1][j];
                dp[i][j]=min(inc,exc);
            }
        }
        
        if(dp[n][amount]!=1e9)
            return dp[n][amount];
        else
            return -1;
    }
};