//https://leetcode.com/problems/sum-of-digits-of-string-after-convert/
class Solution {
public:
   
    int getLucky(string s, int k) {
        int n=s.length(),sum=0;
        
        for(int i=0;i<n;i++)
        {
            int x=s[i]-'a'+1;
            
            sum+=x/10+x%10;
        }
        
        string str=to_string(sum);
        
        k--;
        
        while(k--)
        {
            str=to_string(sum);
            sum=0;
            for(int i=0;i<str.length();i++)
            {
                sum+=str[i]-'0';
            }
        }
        
        return sum;
    }
};