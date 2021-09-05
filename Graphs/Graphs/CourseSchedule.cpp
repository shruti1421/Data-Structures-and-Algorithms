//https://leetcode.com/problems/course-schedule/
class Solution {
public:
    bool detectCycle(int index, vector<vector<int>> &adj, vector<int> &vis, vector<int>&dfsVis)
    {
        vis[index]=1;
        dfsVis[index]=1;
        
        for(auto &x: adj[index])
        {
            if(!vis[x])
            {
                if(detectCycle(x,adj,vis,dfsVis))
                    return true;
            }else if(dfsVis[x])
                return true;
        }
        
        dfsVis[index]=0;
        
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> vis(numCourses,0),dfsVis(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i]&&adj[i].size()>0)
            {
                if(detectCycle(i,adj,vis,dfsVis))
                    return false;
            }
        }
        
        return true;
    }
};