//https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(int *arr, int n) {
        // code here
        
        int x=arr[0];
        
        for(int i=1;i<n;i++)
           x^=arr[i];
           
        for(int i=0;i<n;i++)
            x^=(i+1);
        
        int s=x & ~(x - 1);
        
        int res1=0,res2=0;
        
        for(int i=0;i<n;i++)
        {
            if((s&arr[i])!=0)
                res1^=arr[i];
            else
                res2^=arr[i];
        }
    
        for(int i=0;i<n;i++)
        {
            if((s&(i+1)))
                res1^=(i+1);
            else
                res2^=(i+1);
        }
    
        vector<int> ans(2,0);
        
        ans[0]=res1,ans[1]=res2;
        
        int a=0,b=0;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]==res1)
                a++;
        }
        
        if(a==0)
        {
            ans[0]=res2;
            ans[1]=res1;
        }else
        {
            ans[0]=res1;
            ans[1]=res2;
        }

        return ans;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends