//https://leetcode.com/problems/maximum-number-of-points-with-cost/
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        long long m=points.size(),n=points[0].size();
        
        vector<vector<long long>> dp(m,vector<long long>(n,0));
        
        for(int i=0;i<n;i++)
            dp[0][i]=points[0][i];
        
        
        for(int i=1;i<m;i++)
        {
            vector<long long> left(n,0);
            vector<long long> right(n,0);
            left[0]=dp[i-1][0];
            for(int j=1;j<n;j++)
            {
                left[j]=max(dp[i-1][j],left[j-1]-1);
              
            }
            right[n-1]=dp[i-1][n-1];
             for(int j=n-2;j>=0;j--)
            {
                right[j]=max(dp[i-1][j],right[j+1]-1);
               
            }
            
            for(int j=0;j<n;j++)
            {
                dp[i][j]=max(left[j],right[j])+points[i][j];
            }
        }
        
        long long maxi=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            if(dp[m-1][i]>maxi)
                maxi=dp[m-1][i];
        }
        
        return maxi;
    }
};