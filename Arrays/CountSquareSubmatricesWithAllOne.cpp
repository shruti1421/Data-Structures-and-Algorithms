//https://leetcode.com/problems/count-square-submatrices-with-all-ones/
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int m=matrix.size(),n=matrix[0].size(), ans=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0)
                {
                    ans+=matrix[i][j];
                    continue;
                }
                
                if(matrix[i][j]==1)
                {
                    matrix[i][j]=min(min(matrix[i-1][j],matrix[i-1][j-1]),matrix[i][j-1])+1;
                }
                
                ans+=matrix[i][j];
            }
        }
        
        return ans;
    }
};