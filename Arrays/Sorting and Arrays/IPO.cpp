//https://leetcode.com/problems/ipo/
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        
        priority_queue<pair<int,int>> pq;
        
        for(int i=0;i<n;i++)
        {
            pq.push({profits[i],capital[i]});
        }
        
        while(!pq.empty()&&k>0)
        {
            queue<pair<int,int>> q;
            while(pq.top().second>w&&!pq.empty())
            {
                q.push(pq.top());
                pq.pop();
            }
            
            if(pq.empty())
                return w;
            
            w+=pq.top().first;
            pq.pop();
            k--;
            
            while(!q.empty())
            {
                pq.push(q.front());
                q.pop();
            }
        }
        
        return w;
    }
};