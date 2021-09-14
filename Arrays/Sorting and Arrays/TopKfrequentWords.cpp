//https://leetcode.com/problems/top-k-frequent-words/
//O(nlogk) time and O(n) extra space
class Solution {
public:
    class Compare{
        public:
            bool operator() (const pair<int,string> a, const pair<int,string> b)
           {
                if(a.first==b.first)
                    return a.second<b.second;
                else return a.first>b.first;
            }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        int n=words.size();
        
        map<string,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[words[i]]++;
        }
        
        priority_queue<pair<int,string>, vector<pair<int,string>>, Compare > pq;
        
        for(auto &x: mp)
        {
            pq.push(make_pair(x.second,x.first));
            
            if(pq.size()>k)
                pq.pop();
        }
        
        vector<string> ans;        
        
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};