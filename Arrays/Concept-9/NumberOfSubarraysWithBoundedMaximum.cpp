//https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
class Solution {
public:
    int count(int bound, vector<int> &nums)
    {
        int cnt=0,ans=0;
        for(auto &x: nums)
        {
            if(x<=bound)
                cnt++;
            else
                cnt=0;
            
            ans+=cnt;
        }
        
        return ans;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
    
        return count(right,nums)-count(left-1,nums);
    }
};