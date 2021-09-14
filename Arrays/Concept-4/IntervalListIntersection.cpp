//https://leetcode.com/problems/interval-list-intersections/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int start,end,n=firstList.size(),m=secondList.size();
        vector<vector<int>> res;
        
        int a=0,b=0;
        
        while(a<n&&b<m)
        {
            int s1=firstList[a][0],e1=firstList[a][1],s2=secondList[b][0],e2=secondList[b][1];
            if(s1<=e2&&e1>=s2)
            {
                int start=max(s1,s2);
                int end=min(e1,e2);
                
                res.push_back({start,end});
            }
            
            if(e1>e2)
                b++;
            else if(e2>e1)
                a++;
            else 
            {
                a++;
                b++;
            }
        }
        
        sort(res.begin(),res.end());
        
        return res;
    }
};