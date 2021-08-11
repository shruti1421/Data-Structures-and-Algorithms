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
        
        priority_queue<int> p;
        int i=0;
        while(i<k)
        {
            p.push(arr[i]);
            i++;
        }
        
        ans.push_back(p.top());
        
        int last=0,next=k;
        
        priority_queue<int> del_q;
        
        del_q.push(arr[last]);
        
        while(next<n)
        {
            p.push(arr[next]);
            
            while(!del_q.empty()&&p.top()==del_q.top())
            {
                del_q.pop();
                p.pop();
            }
            
            ans.push_back(p.top());
            
           
            
            last++;
            next=last+k;
            
            del_q.push(arr[last]);
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



A neat little trick to handle deletes for a priority_queue STL - use another priority_queue, say, del_pq. Keep inserting all the delete values to this. When you are popping values from the original priority queue, check with top of del_pq and see if we wanted to delete it. If it matches, delete the value from the original priority_queue.

This method implements a way to lazily delete the values in our original priority queue. Can take up twice the memory, but average delete and inserts remain O(logN).
