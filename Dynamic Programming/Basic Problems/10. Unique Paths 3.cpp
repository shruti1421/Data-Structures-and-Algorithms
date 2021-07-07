/*
On a 2-dimensional grid, there are 4 types of squares:

    1 represents the starting square.  There is exactly one starting square.
    2 represents the ending square.  There is exactly one ending square.
    0 represents empty squares we can walk over.
    -1 represents obstacles that we cannot walk over.

Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 

Example 1:

Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

Example 2:

Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

Example 3:

Input: [[0,1],[2,0]]
Output: 0
Explanation: 
There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.

 

Note:

    1 <= grid.length * grid[0].length <= 20

*/

class Solution {
public:
    int ans=0;
    
    bool check(vector<vector<int>> &grid){
        int m=grid.size(), n=grid[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                    return false;
            }
        }
        
        return true;
    }
    
    void extendPath(vector<vector<int>> grid, int i, int j)
    {
        int m=grid.size(), n=grid[0].size();
        
        
        if(grid[i][j]==2)
        {
            if(check(grid))
                ans++;
            return;
        }
        
        grid[i][j]=-1;
        
        if((j+1)<n){
            if(grid[i][j+1]!=-1)
                extendPath(grid,i,j+1);
        }
            
        if((i+1)<m){
            if(grid[i+1][j]!=-1)
                 extendPath(grid,i+1,j);
        }
           
        if((j-1)>=0){
            if(grid[i][j-1]!=-1)
                extendPath(grid,i,j-1);
        }
            
        if((i-1)>=0){
            if(grid[i-1][j]!=-1)
                 extendPath(grid,i-1,j);
        }
           
        
        return;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
     
        int m=grid.size(), n=grid[0].size();
        
        
        int i,j,z=0;
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    z=1;
                    break;
                }
            }
            
            if(z==1)
                break;
        } 
        
        grid[i][j]=-1;
        
        
         if((j+1)<n){
            if(grid[i][j+1]!=-1)
                extendPath(grid,i,j+1);
        }
            
        if((i+1)<m){
            if(grid[i+1][j]!=-1)
                 extendPath(grid,i+1,j);
        }
           
        if((j-1)>=0){
            if(grid[i][j-1]!=-1)
                extendPath(grid,i,j-1);
        }
            
        if((i-1)>=0){
            if(grid[i-1][j]!=-1)
                 extendPath(grid,i-1,j);
        }
        
        
        return ans;
    }
};
