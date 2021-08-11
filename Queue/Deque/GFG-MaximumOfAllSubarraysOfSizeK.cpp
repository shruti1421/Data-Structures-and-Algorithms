//https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1#
// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        
        vector<int> ans;
        
        deque<int> d;
        
        int i=0,maxi=arr[0],index=0;
        
        while(i<k)
        {
            while(!d.empty()&&arr[d.back()]<=arr[i])
                  d.pop_back();
            
            d.push_back(i);
            
            i++;
        }
        
        ans.push_back(arr[d.front()]);
        
        for(i=k;i<n;i++)
        {
            while(!d.empty()&&d.front()<=i-k)
               d.pop_front();
               
            while(!d.empty()&&arr[d.back()]<=arr[i])
                  d.pop_back();
            
            d.push_back(i);
            
            ans.push_back(arr[d.front()]);
        }
     
        return ans;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends