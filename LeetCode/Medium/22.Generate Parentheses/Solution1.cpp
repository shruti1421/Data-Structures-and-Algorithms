//Backtracking Solution

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<string> answer;
    
  
    
    void arrangements( string curr, int open, int close, int max){
    
        if(curr.length()==2*max){
            answer.push_back(curr);
        }
        else{
            if(open<max)arrangements(curr+"(",open+1,close,max);
            if(close<open)arrangements(curr+")",open,close+1,max);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        int i=0;
        
        
        arrangements("",0,0,n);
        
      
        return answer;
    }
};
