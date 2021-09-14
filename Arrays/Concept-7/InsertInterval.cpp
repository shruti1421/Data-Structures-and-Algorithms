//https://leetcode.com/problems/insert-interval/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int n=intervals.size()+1;
        
        intervals.push_back(newInterval);
        
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> ans;
        
        ans.push_back(intervals[0]);
        
        for(int i=1;i<n;i++)
        {
            vector<int> v=ans.back();
            
            if(v[1]>=intervals[i][0])
            {
                ans.pop_back();
                ans.push_back({v[0],max(v[1],intervals[i][1])});
            }
            else
                ans.push_back(intervals[i]);
        }
        
        return ans;
    }
};