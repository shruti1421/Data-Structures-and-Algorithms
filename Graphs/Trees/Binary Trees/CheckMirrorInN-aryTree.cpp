//https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1#
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        
        unordered_map<int,vector<int>> mpA;
        
        for(int i=0;i<2*e;i+=2)
        {
            mpA[A[i]].push_back(A[i+1]);
        }
        
        unordered_map<int,vector<int>> mpB;
        
        for(int i=0;i<2*e;i+=2)
        {
            mpB[B[i]].push_back(B[i+1]);
        }
        
        for(auto &x: mpA)
        {
            if(mpB.find(x.first)==mpB.end())
            return 0;
            else if(mpB[x.first].size()!=x.second.size())
            return 0;
            else{
                reverse(mpB[x.first].begin(),mpB[x.first].end());
                
                if(mpB[x.first]!=x.second)
                return 0;
                
            }
        }
        
        return 1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends