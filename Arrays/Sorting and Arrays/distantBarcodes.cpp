//Do it in O(N) time
//https://leetcode.com/problems/distant-barcodes/
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n=barcodes.size();
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[barcodes[i]]++;
        }
        int i=0;
        
        priority_queue<pair<int,int>> pq;
        
        for(auto &x:mp)
        {
            pq.push({x.second,x.first});
        }
        
        while(i<n)
        {
            barcodes[i++]=pq.top().second;
            int x=pq.top().second,y=pq.top().first;
            pq.pop();
            
            if(i<n)
            {
            barcodes[i++]=pq.top().second;
            int x2=pq.top().second,y2=pq.top().first;
            pq.pop();
            pq.push({y2-1,x2});
            }
            
            pq.push({y-1,x});
        }
        
        return barcodes;
    }
};