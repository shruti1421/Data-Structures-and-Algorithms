/*
Remove Duplicates in an array
We are given an array we have to delete all the duplicate elements present in the array.

The following code takes
Time Complexity: O(n)
Auxillary Space: O(1)
*/


#include<bits/stdc++.h>
using namespace std;


int removeDuplicate(int a[], int n)
{
    sort(a,a+n);
    
    
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=a[i+1])
        {
            a[j++]=a[i];
        }
    }
    return j;
}

int main() {
	int n;
	cin>>n;
	int a[n];
	
	for(int i=0;i<n;i++)
	cin >> a[i];
	
	n=removeDuplicate(a,n);
	
	for(int i=0;i<n;i++)
	{
	    cout << a[i] << " ";
	}
	return 0;
}
