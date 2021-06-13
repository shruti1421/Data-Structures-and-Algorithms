class Solution {
public:
    bool checkMagic(vector<vector<int>> &row,vector<vector<int>> &column,vector<vector<int>> &d1,vector<vector<int>> &d2,vector<vector<int>> &grid,int a,int b, int k)
    {
        int m=a+k,n=b+k;       
        long long sum=row[a][n-1];
        
        if((b-1)>=0)
            sum-=row[a][b-1];
        
        for(int i=a+1;i<m;i++)
        {
            long long temp= row[i][b+k-1];
            
            if((b-1)>=0)
            temp-=row[i][b-1];
            
            if(temp!=sum)
                return false;
        }
        
          for(int i=b;i<n;i++)
        {
            long long temp= column[a+k-1][i];
              
              if((a-1)>=0)
            temp-=column[a-1][i];
            
            if(temp!=sum)
                return false;
        }
        
        long long d1sum=d1[a+k-1][b+k-1];
        
        if((b-1)>=0&&(a-1)>=0)
            d1sum-=d1[a-1][b-1];
        
        long long d2sum=d2[a+k-1][b];
        
        if((a-1)>=0&&(b+k)<grid[0].size())
            d2sum-=d2[a-1][b+k];
        
        if(d1sum!=sum||d2sum!=sum)
            return false;
        
        return true;
    }
    
    
    int largestMagicSquare(vector<vector<int>>& grid) {
       
        int mini=1;
        
        int maxi=min(grid.size(),grid[0].size());
        
        int m=grid.size(),n=grid[0].size();
        
        vector<vector<int>> row,column,d1,d2;
        row=grid;
        column=grid;
        d1=grid;
        d2=grid;
        
        //Row Sum
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                row[i][j]+=row[i][j-1];
            }
        }
        
        
        //Column Sum
         for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                column[j][i]+=column[j-1][i];
            }
        }
        
        //d1 Sum
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                d1[i][j]+=d1[i-1][j-1];
            }
        }
        
        //d2 Sum
        for(int i=1;i<m;i++)
        {
            for(int j=n-2;j>=0;j--)
            {
                d2[i][j]+=d2[i-1][j+1];
            }
        }
        for(int k=maxi;k>mini;k--){
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                
                    if((i+k)<=m&&(j+k)<=n)
                    {
                        if(checkMagic(row,column,d1,d2,grid,i,j,k))
                        {
                            return k;
                        }
                    }
                
            }
        }}
        
        return mini;
    }
};
