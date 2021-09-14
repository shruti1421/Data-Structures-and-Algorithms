//https://leetcode.com/problems/next-permutation/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n=nums.size();
        
        priority_queue<pair<int,int>> pq;
        int j=0,i;
        for(i=n-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                j=i;
                break;
            }
        }
        if(j!=0)
        {
            int x=j;
            for(i=j;i<n;i++)
            {
                if(nums[j-1]>=nums[i])
                {
                    x=i-1;
                    break;
                }
            }
            
            if(i==n)
                x=i-1;
            
            swap(nums[j-1],nums[x]);
        }
        sort(nums.begin()+j,nums.end());
        return;
    }
};