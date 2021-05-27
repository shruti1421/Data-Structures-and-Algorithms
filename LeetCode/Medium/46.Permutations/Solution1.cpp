#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   
  
    void permutationFun(vector<vector<int>> &answer,vector<int> nums, int l, int r){
        if(l==r)
        {
            answer.push_back(nums);
        }else{
            for(int i=l;i<=r;i++)
            {
                swap(nums[l],nums[i]);
                
                permutationFun(answer,nums,l+1,r);
                
                swap(nums[l],nums[i]);
            }
        }
        
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int l = 0, r=nums.size()-1;
        
       
         vector<vector<int>> answer;
        
        permutationFun(answer,nums,l,r);
        

        
        return answer;
    }
};
