//https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length(),ans=INT_MIN;
        
        unordered_map<char,int> vis;
        
        int start=0,end=0;
        
        while(start<=end&&end<n)
        {
            ans=max(ans,end-start);
            
            if(vis.find(s[end])==vis.end())
            {
                vis.insert({s[end],end});
                end++;
            }
            else
            {
                if(vis[s[end]]+1>start)
                    start=vis[s[end]]+1;
                vis[s[end]]=end;
                end++;
            }
        }
        
        ans=max(ans,end-start);
        
        return ans;
    }
};