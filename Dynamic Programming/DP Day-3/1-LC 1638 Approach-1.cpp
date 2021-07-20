//https://leetcode.com/problems/count-substrings-that-differ-by-one-character/
class Solution {
public:
    int countSubstrings(string s, string t) {
        multimap<string,int> substrS,substrT;
        
        int n=s.length(),m=t.length();
        
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                string str=s.substr(i,j-i+1);
                substrS.insert(make_pair(str,1));
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=i;j<m;j++)
            {
                string str=t.substr(i,j-i+1);
                substrT.insert(make_pair(str,1));
            }
        }
        
        int cnt=0;
        
        for(auto &x: substrS)
        {
            for(auto &y: substrT)
            {
                if(x.first==y.first||x.first.length()!=y.first.length())
                    continue;
                int k=x.first.length(),z=0;
                
                string s1=x.first,s2=y.first;
                
                for(int i=0;i<k;i++)
                {
                    if(s1[i]!=s2[i])
                        z++;
                }
                
                if(z==1)
                    cnt++;
            }
        }
        
        return cnt;
    }
};