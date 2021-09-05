//https://leetcode.com/problems/coin-change-2/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if(j==0)
                    dp[i][j]=1;
                else if(i==0)
                    dp[i][j]=0;
                else
                {
                    int inc,exc;
                    
                    if(coins[i-1]>j)
                        inc=0;
                    else
                        inc=dp[i][j-coins[i-1]];
                    exc=dp[i-1][j];
                    dp[i][j]=inc+exc;
                }
            }
        }
        
        return dp[n][amount];
    }
};