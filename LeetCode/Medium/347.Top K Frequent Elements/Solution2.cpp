//Using Bucket Sort
class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
     
        vector<int> result;
        
        if(!nums.size())return result;
        
        unordered_map<int,int> count;
        
        for(auto num: nums)
            count[num]++;
        
        vector<vector<int>> bucket_sort(nums.size()+1);
        
        for(auto x: count){
            bucket_sort[x.second].push_back(x.first);
        }
        
     
        
        for(int i=bucket_sort.size()-1;i>=0;i--){
            for(int j=0;j<bucket_sort[i].size();j++)
            {
                result.push_back(bucket_sort[i][j]);
                
                if(result.size()==k)
                    return result;
            }
        }
        
        return result;
    }
};

