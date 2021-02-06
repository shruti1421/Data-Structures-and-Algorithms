//Index of first occurrence (Binary Search)

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
			{
				cout << mid ;
				return 0;
			}
			else
				high = mid - 1;
		}
	}

	cout << "-1";
	return 0;
}
