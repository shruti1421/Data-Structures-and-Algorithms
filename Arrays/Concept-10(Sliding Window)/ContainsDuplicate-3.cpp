//https://leetcode.com/problems/contains-duplicate-iii/
//IMP

//O(nlogk) time and O(k) space
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n=nums.size();
        
        if(n==1||k==0)
            return false;
        
        multiset<long long> dup;
        
        int i=0;
        
        while(i<n)
        {
            
            if(dup.size()>k)
                dup.erase(nums[i-k-1]);
                
                auto index=dup.lower_bound((long long)nums[i]-(long long)t);
                
                if(index!=dup.end()&&abs(nums[i]-(*index))<=t) return true;
                 
                dup.insert(nums[i]);
            i++;
        }
        
        return false;
    }
};