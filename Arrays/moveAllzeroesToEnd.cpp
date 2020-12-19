/*
Move all Zeroes to End
We are given an array containing integers we need to move all the zeroes present in the array to the end of it.


The following code takes
Time Complexity: O(n)
Auxillary Space: O(1)
*/


#include<bits/stdc++.h>
using namespace std;


void moveAllzeroesToEnd(int a[], int n)
{
    int count=0;
    
    for(int i=0;i<n;i++)
    {
        if(a[i]!=0)
        {
            int x=a[i];
            a[i]=a[count];
            a[count]=x;
            count++;
        }
    }
}

int main() {
	int n;
	cin>>n;
	int a[n];
	
	for(int i=0;i<n;i++)
	cin >> a[i];
	
	moveAllzeroesToEnd(a,n);
	
	for(int i=0;i<n;i++)
	{
	    cout << a[i] << " ";
	}
	return 0;
}
