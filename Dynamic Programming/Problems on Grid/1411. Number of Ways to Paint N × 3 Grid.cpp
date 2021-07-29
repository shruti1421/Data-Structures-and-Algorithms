//https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid
class Solution {
public:
    const unsigned long long MOD=1e9+7;
    int numOfWays(int n) {
        
        unsigned long long three=6,two=6;
        
        n--;
        
       while(n--)
       {
           unsigned long long temp3,temp2;
           
           temp3=(((three%MOD)*2%MOD)+((two%MOD)*2%MOD))%MOD;
           temp2=(((three%MOD)*2%MOD)+((two%MOD)*3%MOD))%MOD;
           
           three=temp3;
           two=temp2;
       }
        
        
        return (three%MOD+two%MOD)%MOD;
        
    }
};