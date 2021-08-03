#include<bits/stdc++.h>
using namespace std;

const long long int mod = 1000000007;

long long int BinPower(long long int n, long long int m)
{
        long long int res = 1;
        while (m > 0)
        {
                if (m % 2 != 0)
                        res = ((res % mod) * (n % mod)) % mod;
                m /= 2;
                n = ((n % mod) * (n % mod)) % mod;
        }

        return res;
}

int main()
{
        cout << BinPower(10, 9) << " ";

        return 0;
}