//Count Occurrences in a Sorted Array(Binary Search)
//TC: O(logn)

#include<bits/stdc++.h>
using namespace std;

int firstOcc(int a[], int n, int search)
{

	int high = n - 1, low = 0, mid;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (a[mid] > search)
			high = mid - 1;
		if (a[mid] < search)
			low = mid + 1;
		if (a[mid] == search)
		{
			if (mid == 0 || a[mid] != a[mid - 1])
				return mid;
			else
				high = mid - 1;
		}
	}


	return -1;
}

int lastOcc(int a[], int n, int search)
{

	int high = n - 1, low = 0, mid;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (a[mid] > search)
			high = mid - 1;
		if (a[mid] < search)
			low = mid + 1;
		if (a[mid] == search)
		{
			if (mid == n - 1 || a[mid] != a[mid + 1])
				return mid;
			else
				low = mid + 1;
		}
	}

	return -1;
}

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

	int first = firstOcc(a, n, search);

	int last = lastOcc(a, n, search);

	if (first == -1)
		cout << 0;
	else
		cout << last - first + 1;

}
