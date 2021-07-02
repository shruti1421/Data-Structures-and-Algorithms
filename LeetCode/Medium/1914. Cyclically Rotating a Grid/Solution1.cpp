class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
      int top=0,left=0,right=grid[0].size()-1,bottom=grid.size()-1;
        
        while(top<bottom&&left<right){
           
            int t=2*(bottom+1-top)+2*(right+1-left)-4;
            
            t=k%t;
            
            while(t--)
            {
                int temp=grid[top][left];
                
                for(int j=left;j<right;j++)
                {
                    grid[top][j]=grid[top][j+1];
                }
                
                for(int i=top;i<bottom;i++)
                {
                    grid[i][right]=grid[i+1][right];
                }
                
                for(int j=right;j>left;j--)
                {
                    grid[bottom][j]=grid[bottom][j-1];
                }
                
                for(int i=bottom;i>top;i--)
                {
                    grid[i][left]=grid[i-1][left];
                }
                
                grid[top+1][left]=temp;
            }
            
            top++,left++,bottom--,right--;
        }
        
        return grid;
    }
};
