class Solution {
public:
    
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        
        int ans=0;
        
        for(int i=1;i<n;i++)
        {
            int leftLess=0,leftGreater=0,rightLess=0,rightGreater=0;
            
            for(int j=0;j<i;j++)
            {
                if(rating[j]<rating[i])
                    leftLess++;
                else
                    leftGreater++;
            }
            
             for(int j=i+1;j<n;j++)
            {
                if(rating[j]<rating[i])
                    rightLess++;
                else
                    rightGreater++;
            }
            
            ans+= leftLess*rightGreater+leftGreater*rightLess;
        }
        
        
        return ans;

    }
};