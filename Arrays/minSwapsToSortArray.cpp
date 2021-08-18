//https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
#include<bits/stdc++.h>
using namespace std;

int minswaps(vector<int> a, int n)
{
        vector<pair<int, int>> vp;

        for (int i = 0; i < n; i++)
        {
                vp.push_back({a[i], i});
        }

        sort(vp.begin(), vp.end());

        vector<bool> vis(n, 0);

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
                if (vis[i] || vp[i].second == i)
                        continue;
                else
                {
                        int j = i;
                        int cycles = 0;
                        while (!vis[j])
                        {
                                cycles++;
                                vis[j] = 1;
                                j = vp[j].second;
                        }

                        if (cycles > 0)
                                ans += (cycles - 1);
                }
        }

        return ans;
}

int main() {
        vector<int> a = {4, 5, 2, 1, 5};
        cout << minswaps(a, 5) << "\n";
        return 0;
}