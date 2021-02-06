//Binary Search
//We are given an sorted array, we need to find the position of given element in the array and print its position if it is present otherwise print -1.
//ex: I/P: arr[]={10,20,30,40,50,60} O/P: 1
//TC: O(logn)  AS: O(1)

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int n;

	cin >> n;

	int a[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int search;

	cin >> search;

	int low = 0, high = n - 1, mid = (low + high) / 2;

	while (low < high)
	{
		mid = (low + high) / 2;

		if (a[mid] == search)
		{
			cout << mid ;
			return 0;
		}

		if (a[mid] > search)
			high = mid - 1;

		if (a[mid] < search)
			low = mid + 1;
	}

	cout << "-1";
	return 0;
}
