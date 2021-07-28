//https://leetcode.com/problems/maximize-distance-to-closest-person/
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size(),c=1,maxi=INT_MIN;
        
        for(int i=1;i<n;i++)
        {
            if(seats[i]==0&&seats[i]==seats[i-1])
                c++;
            else
                c=1;
            
            if(c>maxi)
                maxi=c;
        }
        
        if(maxi%2!=0)
            maxi=maxi/2+1;
        else
            maxi=maxi/2;
        
        if(seats[0]==0)
        {
            c=0;
            for(int i=0;i<n&&seats[i]==0;i++)
                c++;
        }
        
        maxi=max(c,maxi);
        
          if(seats[n-1]==0)
        {
            c=0;
            for(int i=n-1;i>=0&&seats[i]==0;i--)
                c++;
        }
        
        maxi=max(c,maxi);
        
        
        return maxi;
    }
};