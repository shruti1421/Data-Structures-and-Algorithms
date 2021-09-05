//https://leetcode.com/problems/reconstruct-itinerary/
class Solution {
public:

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n=tickets.size();
        
        unordered_map<string,multiset<string>> adj;
        
        for(int i=0;i<n;i++)
        {
            string a=tickets[i][0],b=tickets[i][1];
            
            adj[a].insert(b);
        }
        
        
        vector<string> ans;
        
        stack<string> traverse;
        traverse.push("JFK");
        
        while(!traverse.empty())
        {
            string str=traverse.top();
            
            if(adj[str].size()==0)
            {
                ans.push_back(str);
                traverse.pop();
            }
            else{
                auto depart= adj[str].begin();
                traverse.push(*depart);
                adj[str].erase(depart);
            }
        }
        
        reverse(ans.begin(),ans.end());
      
        return ans;
    }
};