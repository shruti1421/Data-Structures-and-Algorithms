//counting left and right of each element which are not equal in s and t
class Solution {
public:
    int countSubstrings(string s, string t) {
        multimap<string,int> substrS,substrT;
        
        int n=s.length(),m=t.length(),cnt=0;
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s[i]!=t[j])
                {
                    int l=1,r=1;
                    int x=i-1,y=j-1;
    
                    while(x>=0&&y>=0&&s[x]==t[y])
                    {
                        l++;
                        x--;
                        y--;
                    }
                    x=i+1,y=j+1;
                    while(x<n&&y<m&&s[x]==t[y])
                    {
                        r++;
                        x++;
                        y++;
                    }
                    
                    cnt+=l*r;
                }
            }
        }
        
        return cnt;
    }
};