//https://leetcode.com/problems/subarray-product-less-than-k/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        
        int n=nums.size();
        
        int left=0,right=0;
        int prod=1;
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(prod*nums[i]<k)
            {
                prod=prod*nums[i];
                right++;
            }
            else
            {
               prod=prod*nums[i]; 
               while(prod>=k)
               {
                   prod=prod/nums[left];
                   left++;
               }
                right++;
            }
            
            ans+=right-left;
        }
        
        return ans;
    }
};