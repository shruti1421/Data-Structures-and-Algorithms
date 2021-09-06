//https://leetcode.com/problems/number-of-operations-to-make-network-connected/
class Solution {
public:
    void dfs(int index, vector<int> &vis, vector<vector<int>> &adj)
    {
        if(vis[index])return;
        
        vis[index]=1;
        
        for(int i=0;i<adj[index].size();i++)
        {
            dfs(adj[index][i],vis,adj);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int edges=connections.size();
        
        if(edges<n-1)
            return -1;
        
        vector<vector<int>> adj(n);
        
        for(int i=0;i<edges;i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        int c=0;
        
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                c++;
                dfs(i,vis,adj);
            }
        }
        
        return c-1;
    }
};