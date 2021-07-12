//https://leetcode.com/problems/count-square-submatrices-with-all-ones/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int m=matrix.size(),n=matrix[0].size();
        
        
        int dp[m][n];
        
        for(int i=0;i<m;i++)
            dp[i][0]=matrix[i][0];
        
        for(int i=0;i<n;i++)
           dp[0][i]=matrix[0][i];
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]==1)
                {
                    dp[i][j]=min(min(dp[i-1][j],dp[i-1][j-1]),dp[i][j-1])+1;
                }else
                    dp[i][j]=matrix[i][j];
            }
        }
        
        int ans=0;
        
         for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans+=dp[i][j];
            }
        }
        
        return ans;
    }
};