//Question: https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1#
//https://www.geeksforgeeks.org/find-first-and-last-positions-of-an-element-in-a-sorted-array/
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


// } Driver Code Ends


vector<int> binarySearch(int arr[], int n, int start, int end, int x)
{
     vector<int> ans;
     
     ans.push_back(INT_MAX);
     ans.push_back(INT_MIN);
     
     if(start>end)
     return ans;
     
     int mid=(start+end)/2;
     
     int mini=INT_MAX,maxi=INT_MIN;
     
        while(start<=end&&start>=0&&end<n)
       {
            mid=(start+end)/2;
        
            if(arr[mid]<x)
                start=mid+1;
            else if(arr[mid]>x)
                end=mid-1;
            else if(arr[mid]==x)
                {
                    maxi=max(maxi,mid);
                    mini=min(mini,mid);
                    if(mid+1<=end&&arr[mid+1]==x)
                    {
                        vector<int> temp=binarySearch(arr,n,mid+1,end,x);
                        maxi=max(maxi,temp[1]);
                    }
                    
                    if(mid-1>=start&&arr[mid-1]==x)
                    {
                        vector<int> temp=binarySearch(arr,n,start,mid-1,x);
                        mini=min(mini,temp[0]);
                    }
                    
                    break;
                }
        }
        
        ans[0]=mini;
        ans[1]=maxi;
        
        return ans;
     
}

vector<int> find(int arr[], int n , int x )
{
    // code here
    int mini=INT_MAX,maxi=INT_MAX;
    
    
    vector<int> ans=binarySearch(arr,n,0,n-1,x);
    
    if(ans[0]==INT_MAX)
    ans[0]=-1;
    
    if(ans[1]==INT_MIN)
    ans[1]=-1;
    
    return ans ;
}