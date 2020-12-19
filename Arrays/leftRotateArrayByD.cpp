/*
Left Rotate an array by d
We are given an array of size n we need to left rotate this array d times

The following code takes
Time Complexity: O(n)
Auxillary Space: O(1)
*/


#include<bits/stdc++.h>
using namespace std;

void reverse(int a[], int low, int high)
{
    while(low<high)
    {
        int x=a[low];
        a[low]=a[high];
        a[high]=x;
        low++;
        high--;
    }
}

void leftRotateArrayByD(int a[], int n, int d)
{
    reverse(a,0,d-1);
    reverse(a,d,n-1);
    reverse(a,0,n-1);
}

int main() {
	int n,d;
	cin>>n>>d;
	int a[n];
	
	for(int i=0;i<n;i++)
	cin >> a[i];
	
	leftRotateArrayByD(a,n,d);
	
	for(int i=0;i<n;i++)
	{
	    cout << a[i] << " ";
	}
	return 0;
}
