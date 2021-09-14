//https://leetcode.com/problems/assign-cookies/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        int m=g.size(),n=s.size(),a=0,b=0;
        
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        while(a<m&&b<n)
        {
           if(g[a]<=s[b])
           {
               a++;
               b++;
           }
            else
                b++;
        }
        
        return a;
            
    }
};