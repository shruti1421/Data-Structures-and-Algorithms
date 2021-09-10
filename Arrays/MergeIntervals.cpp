//https://leetcode.com/problems/merge-intervals/submissions/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        
        ans.push_back(intervals[0]);
        
        int n=intervals.size();
        
        for(int i=1;i<n;i++)
        {
            vector<int> v=ans.back();
            if(v[1]>=intervals[i][0])
            {
                ans.pop_back();
                ans.push_back({v[0],max(intervals[i][1],v[1])});
            }
            else
                ans.push_back(intervals[i]);
        }
        
        return ans;
    }
};