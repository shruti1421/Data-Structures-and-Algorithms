//https://leetcode.com/problems/spiral-matrix/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
    
        vector<int> ans;
        
        int r=1,c=0;
        int i=0,j=0;
        
        ans.push_back(matrix[0][0]);
        vis[0][0]=1;
        
        int f=1;
        
        while(f)
        {
                j=j+r;
                while(i>=0&&j>=0&&i<m&&j<n&&vis[i][j]==0)
                {
                    ans.push_back(matrix[i][j]);
                    vis[i][j]=1;
                    j+=r;
                }
                    j--;
                
                c=1;
            
                i=i+c;
                while(i>=0&&j>=0&&i<m&&j<n&&vis[i][j]==0)
                {
                    ans.push_back(matrix[i][j]);
                    vis[i][j]=1;
                    i+=c;
                }
                
                    i--;
                
                r=-1;
                
                j=j+r;
                while(i>=0&&j>=0&&i<m&&j<n&&vis[i][j]==0)
                {
                    ans.push_back(matrix[i][j]);
                    vis[i][j]=1;
                    j+=r;
                }
                
                    j++;
                 c=-1;
                
                i=i+c;
                while(i>=0&&j>=0&&i<m&&j<n&&vis[i][j]==0)
                {
                    ans.push_back(matrix[i][j]);
                    vis[i][j]=1;
                    i+=c;
                }
                i++;
                r=1;
        
            
            if((i-1<0||(i-1>=0&&vis[i-1][j]))&&(j-1<0||(j-1>=0&&vis[i][j-1]))&&(i+1>=m||(i+1<m&&vis[i+1][j]))&&(j+1>=n||(j+1<n&&vis[i][j+1])))break;
            
        }
        
        return ans;
    }
};