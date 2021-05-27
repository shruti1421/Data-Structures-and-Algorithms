//Bitmask
//RT:4ms
class Solution {
public:
   
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> answer;
       
       int n=nums.size();
       int powSize=pow(2,n);
        
       for(int counter=0;counter<powSize;counter++)
       {
           vector<int> curr;
           
           for(int i=0;i<n;i++)
           {
               if((counter&(1<<i))!=0)
                   curr.push_back(nums[i]);
           }
           answer.push_back(curr);
       }
        
       return answer;
    }
};
