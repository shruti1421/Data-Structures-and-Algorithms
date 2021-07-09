//Recursive Solution

class Solution {
public:
    
    int ans=0;
    
    bool check(vector<int> arr)
    {
        if(arr[0]>arr[1]&&arr[1]>arr[2])
            return true;
        if(arr[0]<arr[1]&&arr[1]<arr[2])
            return true;
        
        return false;
    }
    
    void buildTeam(vector<int>& rating, vector<int> arr, int index)
    {
        
        
        if(arr.size()==3)
        {
            if(check(arr))
                ans++;
            return;
        }
        
        if(index>=rating.size()-1)
            return;
        
        for(int i=index+1;i<rating.size()-(3-arr.size()-1);i++)
        {
            arr.push_back(rating[i]);
            buildTeam(rating,arr,i);
            arr.pop_back();
        }
    }
    
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        
        vector<int> arr;
    
        
        for(int i=0;i<n-2;i++)
        {
            arr.push_back(rating[i]);
            buildTeam(rating,arr,i);
            arr.pop_back();
        }
        
        
        return ans;
    }
};