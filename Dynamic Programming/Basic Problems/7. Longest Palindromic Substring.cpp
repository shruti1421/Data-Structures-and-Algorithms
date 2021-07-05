/*
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"

Example 3:

Input: s = "a"
Output: "a"

Example 4:

Input: s = "ac"
Output: "a"

 

Constraints:

    1 <= s.length <= 1000
    s consist of only digits and English letters (lower-case and/or upper-case),


*/

class Solution {
public:
    
    int maxLen=INT_MIN;
    string str;
    
    void extendPalindrome(string s, int left, int right){
        
        int n=s.length();
        
        while(left>=0&&right<n)
        {
            if(s[left]!=s[right])
            {
                    return;
            }
            else if((right-left+1)>maxLen)
                {
                    maxLen=right-left+1;
                    str=s.substr(left,right-left+1);
                }
            
            left--;
            right++;
        }
       
       
        return;
    }
    
    string longestPalindrome(string s) {
        
        
        int n=s.length();
        
        
        if(n<=0)return "";
        
        str=s[0];
        maxLen=1;
        
        for(int i=0;i<n;i++)
        {
             extendPalindrome(s,i,i);
            if((i+1)<n)
             extendPalindrome(s,i,i+1);
        }
        
        return str;
    }
};
