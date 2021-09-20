//https://leetcode.com/problems/trapping-rain-water-ii/
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
       int m=heightMap.size(),n=heightMap[0].size();
        
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
       vector<vector<int>> vis(m,vector<int>(n,0));
        
       for(int i=0;i<m;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(i==0||i==m-1||j==0||j==n-1)
               {
                   pq.push({heightMap[i][j],{i,j}});
                   vis[i][j]=1;
               }
           }
       }
        
       int minBdHt=0;
       int vol=0;
        
       
       while(!pq.empty())
       {
           int curr=pq.top().first;
           int r=pq.top().second.first;
           int c=pq.top().second.second;
           pq.pop();
           minBdHt=max(curr,minBdHt);
           
           
           vector<int> dr={0,0,1,-1};
           vector<int> dc={1,-1,0,0};
           
           for(int i=0;i<4;i++)
           {
               int rr=r+dr[i],cc=c+dc[i];
               
               if(rr<m&&rr>=0&&cc<n&&cc>=0&&!vis[rr][cc])
               {
                   pq.push({heightMap[rr][cc],{rr,cc}});
                   vis[rr][cc]=1;
                   
                   if(heightMap[rr][cc]<minBdHt)
                       vol+=minBdHt-heightMap[rr][cc];
               }
           }
       }
        
       return vol;
    }
};