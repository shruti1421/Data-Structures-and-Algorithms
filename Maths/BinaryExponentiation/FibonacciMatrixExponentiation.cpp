#include<bits/stdc++.h>
using namespace std;

const long long int mod = 1000000007;

vector<vector<int>> mutiply(vector<vector<int>> x, vector<vector<int>>y)
{
        int m = x.size(), n = y[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        ans[i][j] = 0;
                        for (int k = 0; k < m; k++)
                        {
                                ans[i][j] += x[i][k] * y[k][j];
                        }
                }
        }

        return ans;
}

vector<vector<int>> BinPower(vector<vector<int>> p, int m)
{
        vector<vector<int>> res = p;
        m--;
        while (m > 0)
        {
                if (m % 2 != 0)
                        res = mutiply(res, p);
                m /= 2;
                p = mutiply(p, p);
        }

        return res;
}

int main()
{

        vector<vector<int>> fact = {{1}, {1}};

        vector<vector<int>> fibFun = {{1, 1}, {1, 0}};

        fact = mutiply(BinPower(fibFun, 3 ), fact);

        cout << fact[0][0] << " " << fact[1][0];

        return 0;
}