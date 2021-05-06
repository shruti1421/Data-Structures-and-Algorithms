/*
Problem

In Kick Start 2020 Round E (you do not need to know anything about the previous problem to solve this one) Sarasvati learned about arithmetic arrays. An arithmetic array is an array that contains at least two integers and the differences between consecutive integers are equal. For example, [9,10]
, [3,3,3], and [9,7,5,3] are arithmetic arrays, while [1,3,3,7], [2,1,2], and [1,2,4]

are not.

Sarasvati again has an array of N
non-negative integers. The i-th integer of the array is Ai

. She can replace at most one element in the array with any (possibly negative) integer she wants.

For an array A
, Sarasvati defines a subarray as any contiguous part of A

. Please help Sarasvati determine the length of the longest possible arithmetic subarray she can create by replacing at most one element in the original array.
Input

The first line of the input gives the number of test cases, T
. T test cases follow. Each test case begins with a line containing the integer N. The second line contains N integers. The i-th integer is Ai

.
Output

For each test case, output one line containing Case #x
: y, where x is the test case number (starting from 1) and y

is the length of the longest arithmetic subarray.
Limits

Time limit: 30 seconds.
Memory limit: 1 GB.
1≤T≤100

0≤Ai≤109

.
Test Set 1

2≤N≤2000

.
Test Set 2

2≤N≤3×105
for at most 10 test cases.
For the remaining cases, 2≤N≤2000

Sample Input
3
4
9 7 5 3
9
5 5 4 5 5 5 4 5 6
4
8 5 2 0

Sample Output
Case #1: 4
Case #2: 6
Case #3: 4

In Sample Case #1, the whole array is an arithmetic array, thus the longest arithmetic subarray is the whole array.

In Sample Case #2, if Sarasvati changes the number at third position to 5
, the array will become [5,5,5,5,5,5,4,5,6]

. The subarray from first position to sixth position is the longest arithmetic subarray.

In Sample Case #3, Sarasvati can change the number at the last position to −1
, to get [8,5,2,−1]. This resulting array is arithmetic. 
*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll longestProgression(vector<ll> d, ll n)
{
        ll ans = 1, i = 0;

        while (i < n)
        {
                ll j = i, c = 0;

                while (d[i] == d[j] && j < n)
                {
                        j++;
                        c++;
                }
                
                ans=max(ans,j-i+1);

                if (j < n)
                    ans=max(ans,j-i+2);

                if ((d[j] + d[j + 1]) == 2 * d[i] && (j + 1) < n)
                {
                        c++;
                        ll k = j + 2;

                        while (d[k] == d[i]&&k<n)
                        {
                                k++;
                                c++;
                        }
                        
                        ans=max(ans,k-i+1);
                }

                i = j;

        }

        return ans;
}

int main()
{

        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);


        ll t, x = 0, n;
        cin >> t;

        while (t--)
        {
                x++;
                cin >> n;

                ll a[n];

                vector<ll> d;

                for (ll i = 0; i < n; i++)
                {
                        cin >> a[i];

                        if (i > 0)
                                d.push_back(a[i] - a[i - 1]);
                }
                
                ll ans=longestProgression(d,n-1);
                
                reverse(d.begin(),d.end());
                
                ans=max(ans,longestProgression(d,n-1));


               

                cout << "Case #" << x << ": " << ans << "\n";
        }

        return 0;
}
