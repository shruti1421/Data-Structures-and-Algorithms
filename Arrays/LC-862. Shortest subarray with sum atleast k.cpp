//https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size(),mini=INT_MAX;
        
        deque<int> d;
        
        vector<int> prefixSum=nums;
        
        for(int i=1;i<n;i++)
            prefixSum[i]+=prefixSum[i-1];
        
        for(int y=0;y<n;y++)
        {
            if(prefixSum[y]>=k)
                mini=min(mini,y+1);
            
            while(d.size()>0&&prefixSum[y]-prefixSum[d.front()]>=k)
            {
                mini=min(mini,y-d.front());
                d.pop_front();
            }
            
            while(d.size()>0&&prefixSum[d.back()]>=prefixSum[y])
                d.pop_back();
            
            d.push_back(y);
        }
        
        if(mini<=n)
        return mini;
        else
        return -1;
    }
};