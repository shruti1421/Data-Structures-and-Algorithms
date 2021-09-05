//https://leetcode.com/problems/course-schedule-ii/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size(), m=numCourses;
        
        vector<vector<int>> adj(m);
        
        for(int i=0;i<n;i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> indeg(m,0);
        
        for(int i=0;i<m;i++)
        {
            for(auto &x: adj[i])
            {
                indeg[x]++;
            }
        }
        
        stack<int> st;
        
        for(int i=0;i<m;i++)
        {
            if(indeg[i]==0)
                st.push(i);
        }
        
        vector<int> ans;
        
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            
            ans.push_back(node);
            
            for(auto &x: adj[node])
            {
                    indeg[x]--;
                    
                    if(indeg[x]==0)
                        st.push(x);
            }
        }
        

        vector<int> v;
        
        if(ans.size()==m)
            return ans;
        else
            return v;
    }
};