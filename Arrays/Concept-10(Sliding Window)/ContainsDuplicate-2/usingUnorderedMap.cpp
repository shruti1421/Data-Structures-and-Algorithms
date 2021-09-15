//https://leetcode.com/problems/contains-duplicate-ii/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        
        int end=0;
        
        unordered_map<int,int> vis;
        
        while(end<n)
        {
            if(vis.find(nums[end])==vis.end())
            {
                vis.insert({nums[end],end});
                end++;
            }
            else
            {
                if(abs(end-vis[nums[end]])<=k)
                    return true;
                
                vis[nums[end]]=end;
                end++;
            }
        }
        
        return false;
    }
};