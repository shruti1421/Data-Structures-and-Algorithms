class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int zeroes=0,p=1;
        
        vector<int>  answer(nums.size());
        
        for(auto& x: nums)
        {
            if(x==0)
                zeroes++;
            else
                p*=x;
        }
        
        if(zeroes>1)
        {
            fill(answer.begin(),answer.end(),0);
        }else{
            if(zeroes==1)
            {
                 for(int i=0;i<nums.size();i++)
                 {
                     if(nums[i]==0)
                         answer[i]=p;
                     else
                         answer[i]=0;
                 }
            }else{
                
                for(int i=0;i<nums.size();i++)
                {
                    answer[i]=p/nums[i];
                }
            }
        }   
        
        return answer;
        
    }
};
