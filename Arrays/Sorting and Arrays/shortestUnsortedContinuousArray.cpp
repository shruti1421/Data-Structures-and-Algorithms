//https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int> lhsmax(n,0),rhsmin(n,0);
        
        int maxi=nums[0];
        
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
            lhsmax[i]=maxi;
        }
        
        int mini=nums[n-1];
        
        for(int i=n-1;i>=0;i--)
        {
            mini=min(nums[i],mini);
            rhsmin[i]=mini;
        }
        
        int left=0,right=n-1;
        
        while(right>=0&&nums[right]==lhsmax[right])
            right--;
        while(left<right&&nums[left]==rhsmin[left])
            left++;
        

        
        return right-left+1;
    }
};