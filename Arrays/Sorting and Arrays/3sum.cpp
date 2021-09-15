//https://leetcode.com/problems/3sum/
//Two Pointer Algo
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        
      
        vector<vector<int>> ans;
        
        unordered_map<string, int> mp;
        
        sort(nums.begin(),nums.end());
        
        if(n==0)
            return ans;
        
        if(nums[0]>0)
            return ans;
        
        if(nums[0]>=0)
        {
            if(n>=3&&nums[1]==0&&nums[2]==0)
            {
                ans.push_back({0,0,0});
                return ans;
            }
            return ans;
        }
        
        for(int i=0;i<n-2;i++)
        {
            int a=i+1,b=n-1,t=nums[i]*(-1);
            
            while(a<b)
            {
                
                if((nums[a]+nums[b])<t)
                    a++;
                else if((nums[a]+nums[b])>t)
                    b--;
                else
                {
                    if(i!=a&&i!=b)
                    {
                       vector<int> v={nums[i],nums[a],nums[b]}; 
                    
                       ans.push_back({nums[i],nums[a],nums[b]});
                        a++,b--;
                       while(a<b&&nums[a]==nums[a-1])
                           a++;
                       while(a<b&&nums[b]==nums[b+1])
                           b--;
                    }
                }
            }
            
            while(i<n-1&&nums[i]==nums[i+1])
                    i++;
        }
        
        return ans;
    }
};