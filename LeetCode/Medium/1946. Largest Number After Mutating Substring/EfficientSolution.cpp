//https://leetcode.com/problems/largest-number-after-mutating-substring/
#include <charconv>
class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int n=num.length();
        
        string temp=num;
        int mutated=0;
        
        for(int i=0;i<n;i++)
        {
           int x=num[i]-'0';
           
           temp[i]='0'+max(x,change[x]);
            
           if(x>change[x]&&mutated)
               break;
            
           mutated|=(change[x]>x);
        
        }
        
        
        return temp;
        
        
    }
};