class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        
        vector<int> time(n,0);
        
        for(int i=0;i<n;i++)
        {
            time[i]=(dist[i]%speed[i]==0)?(dist[i]/speed[i]):(dist[i]/speed[i])+1;
        }
        
        sort(time.begin(),time.end());
        
        int res=0;
        
        for(int i=0;i<n;i++)
        {
            if(i>=time[i])
                return res;
            
            res++;
        }
        
        
        return res;
        
    }
};
