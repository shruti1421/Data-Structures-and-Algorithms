//https://leetcode.com/problems/flood-fill/
class Solution {
public:
    void modifyImage(vector<vector<int>> &image, int sr, int sc,int newColor, vector<vector<int>> &vis, int val)
    {
       int m=image.size(), n=image[0].size();
       if(sr>=m||sc>=n||sr<0||sc<0)
           return;
    
       if(vis[sr][sc]) return;
       vis[sr][sc]=1;
        
        if(image[sr][sc]!=val) return;
        
        image[sr][sc]=newColor;
        
        modifyImage(image,sr+1,sc,newColor,vis,val);
        modifyImage(image,sr,sc+1,newColor,vis,val);
        modifyImage(image,sr-1,sc,newColor,vis,val);
        modifyImage(image,sr,sc-1,newColor,vis,val);
      
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m=image.size(), n=image[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        modifyImage(image,sr,sc,newColor,vis,image[sr][sc]);
        
        return image;
    }
};