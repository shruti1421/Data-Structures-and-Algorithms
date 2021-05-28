class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> answer;
        
        sort(nums.begin(),nums.end());
        
        vector<pair<int,int>> freq;
        
        int f=1;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1]){
                f++;
            }else{
                freq.push_back(make_pair(f,nums[i-1]));
                f=1;
            }
        }
        
        freq.push_back(make_pair(f,nums[nums.size()-1]));
        
        sort(freq.begin(),freq.end());
        reverse(freq.begin(),freq.end());
        
        for(auto x: freq)
        {
            if(k==0)
                break;
            
            answer.push_back(x.second);
            k--;
        }
        
        return answer;
    }
};
