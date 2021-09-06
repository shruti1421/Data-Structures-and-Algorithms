//https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1#
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    int find(vector<int> start, vector<int> tar, int n)
    {
        int minS=INT_MAX;
        vector<vector<int>> vis(n+1,vector<int>(n+1,0));
        
        if(start[0]>n||start[0]<=0||start[1]>n||start[1]<=0)
        return -1;
        
        int x=start[0],y=start[1];
        
        vis[x][y]=1;
        
        queue<vector<int>> q;
        
        q.push({0,x,y});
        
            // x and y direction, where a knight can move
        int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
        int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

        
        while(!q.empty())
        {
            vector<int> curr = q.front();
            q.pop();
            
            if(curr[1]==tar[0]&&curr[2]==tar[1])
            {
                minS=min(minS,curr[0]);
                continue;
            }
            
            x=curr[1];
            y=curr[2];
            
            for(int i=0;i<8;i++)
            {
                x=curr[1]+dx[i];
                y=curr[2]+dy[i];
                
                if(x<=n&&x>0&&y<=n&&y>0&&!vis[x][y])
                {
                    vis[x][y]=1;
                    q.push({curr[0]+1,x,y});
                }
            }

        }
        
        return minS;
        
    }
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here

	    
	    return 	find(KnightPos,TargetPos,N);;
	}
};