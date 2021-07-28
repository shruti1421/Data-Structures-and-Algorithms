//https://leetcode.com/problems/minimum-size-subarray-sum/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(),sum=0;
    
        int j=0,mini=INT_MAX;
        
        for(int i=0;i<n;i++)
        {
             sum+=nums[i];
             
             while(sum>=target)
             {
                 mini=min(mini,i-j+1);
                 sum-=nums[j++];
             }
        }
        
        if(mini<=n)
        return mini;
        else
            return 0;
    }
};