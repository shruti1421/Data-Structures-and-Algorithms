//Recursion
//TC:8ms
class Solution {
public:
    void findSubsets(vector<vector<int>> &answer,int i, vector<int> nums, vector<int> curr)
    {
        if(i>=nums.size())
            answer.push_back(curr);
        else{
            findSubsets(answer,i+1,nums,curr);
            curr.push_back(nums[i]);
            findSubsets(answer,i+1,nums,curr);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> answer;
           
       vector<int> curr;
           
       findSubsets(answer,0,nums,curr);
        
       return answer;
    }
};
