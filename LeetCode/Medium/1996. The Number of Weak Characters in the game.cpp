//https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/
#include<bits/stdc++.h>
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n=properties.size();
        
        sort(properties.begin(),properties.end(),cmp);
        
        int maxi=INT_MIN;
        int ans=0;
        
        for(int i=n-1;i>=0;i--)
        {
            if(properties[i][1]<maxi)
                ans++;
            else
                maxi=max(maxi,properties[i][1]);
        }
        
        return ans;
            
    }
};