//https://leetcode.com/problems/3sum-closest/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
               int n=nums.size();
        
      
        vector<vector<int>> ans;
        
        unordered_map<string, int> mp;
        
        sort(nums.begin(),nums.end());
        
        int res=nums[0]+nums[1]+nums[2];
        
        for(int i=0;i<n-2;i++)
        {
            int a=i+1,b=n-1,t=target;
            int sum=nums[i]+nums[a]+nums[b];
            
            while(a<b)
            {
                if(abs(target-sum)<abs(target-res))
                    res=sum;
                
                if(sum<t)
                    a++;
                else
                    b--;
                
                sum=nums[i]+nums[a]+nums[b];
            }
            
            while(i<n-1&&nums[i]==nums[i+1])
                    i++;
        }
        
        return res;
    }
};