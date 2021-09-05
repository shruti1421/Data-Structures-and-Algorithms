//https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>&grid)
    {
      int m=grid.size(),n=grid[0].size();
      grid[row][col]='2';
        
      if(row-1>=0&&grid[row-1][col]=='1')
          dfs(row-1,col,grid);
      if(col-1>=0&&grid[row][col-1]=='1')
          dfs(row,col-1,grid);
      if(row+1<m&&grid[row+1][col]=='1')
          dfs(row+1,col,grid);
      if(col+1<n&&grid[row][col+1]=='1')
          dfs(row,col+1,grid);
    
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
         int c=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    c++;
                    dfs(i,j,grid);
                }
            }
        }
        
        return c;
    }
};