#include<bits/stdc++.h>
using namespace std;

int Power(int a, int power, int mod)
{
        int res = 1;
        while (power > 0)
        {
                if (power % 2 != 0)
                {
                        res = ((res % mod) * (a % mod)) % mod;
                        power--;
                }
                power /= 2;
                a = (a * a) % mod;

        }

        return res;
}

int gcd(int a, int b)
{
        if (b == 0)
                return a;
        return gcd(b, a % b);
}

int moduloInverse(int a, int mod)
{
        if (gcd(a, mod) > 1)
                return -1;
        else
                return Power(a, mod - 2, mod);
}

int main()
{
        cout << moduloInverse(3, 7);
        cout << moduloInverse(6, 12);
        return 0;
}