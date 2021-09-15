class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        
        int end=0;
        
        unordered_set<int> vis;
        
        while(end<n)
        {
            if(vis.size()>k)
                vis.erase(nums[end-k-1]);
            if(vis.find(nums[end])!=vis.end())
                return true;
            vis.insert(nums[end]);
            end++;
        }
        
        return false;
    }
};