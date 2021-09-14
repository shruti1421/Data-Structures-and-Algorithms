//https://leetcode.com/problems/matrix-block-sum/
class Solution {
public:
    int extractSum(int x, int y, int m, int n, vector<vector<int>> &preSum)
    {
        if(x<0||y<0)
            return 0;
        if(x>=m) x=m-1;
        if(y>=n) y=n-1;
        
        return preSum[x][y];
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        
        vector<vector<int>> preSum(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)
                    preSum[i][j]=mat[i][j];
                else if(i==0)
                    preSum[i][j]=preSum[i][j-1]+mat[i][j];
                else if(j==0)
                    preSum[i][j]=preSum[i-1][j]+mat[i][j];
                else
                    preSum[i][j]=preSum[i-1][j]+preSum[i][j-1]-preSum[i-1][j-1]+mat[i][j];
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
               ans[i][j]=extractSum(i+k,j+k,m,n,preSum)-extractSum(i+k,j-k-1,m,n,preSum)-extractSum(i-k-1,j+k,m,n,preSum)+extractSum(i-k-1,j-k-1,m,n,preSum);
            }
        }
        
        return ans;
    }
};