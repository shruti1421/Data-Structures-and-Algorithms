//https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        int n=nums.size();
        int forSum,backSum;
        
        vector<int> ans(n,0);
        
        forSum=0;
        backSum=accumulate(nums.begin(),nums.end(),0);
        
        for(int i=0;i<n;i++)
        {
            if(i>0)
                ans[i]=abs(nums[i]*(i)-forSum)+abs(backSum-nums[i]*(n-i));
            else
                ans[i]=abs(backSum-nums[i]*(n-i));
            
            forSum+=nums[i];
            backSum-=nums[i];
        }
        
        return ans;
    }
};