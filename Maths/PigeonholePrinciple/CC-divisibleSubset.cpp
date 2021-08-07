//https://www.codechef.com/problems/DIVSUBS
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define clr(x) memset(x, 0, sizeof(x))
#define PI 3.1415926535897932384626
#define F first
#define S second
#define pb push_back
#define mp make_pair
typedef pair<int, int>  pii;
typedef vector<int>   vi;
typedef vector<pii>   vpii;
typedef vector<vi>    vvi;
const ll MOD = 1000000007;

//To count numbers of digits in a number
ll countDigits(ll);

//To find greatest common divisor of two numbers
ll gcd (ll, ll);

//To find LCM of two numbers
ll lcm(ll, ll);

//To check if a number is prime or not
bool isPrime(ll);

//To find power n of x
ll power(ll, ll);


ll n, m, k;

void solve()
{
        cin >> n;

        ll pre[n];

        bool f = 0;
        ll index = 0;

        for (ll i = 0; i < n; i++)
        {
                ll x;
                cin >> x;
                if (i == 0)
                        pre[i] = x;
                else
                        pre[i] = pre[i - 1] + x;

                if (pre[i] % n == 0)
                {
                        f = 1;
                        index = i;
                }
        }

        if (f == 1)
        {
                cout << index + 1 << "\n";
                for (ll i = 0; i <= index; i++)
                {
                        cout << i + 1 << " ";
                }
                return;
        }

        vector<ll> count(n, -1);

        for (ll i = 0; i < n; i++)
        {
                if (count[pre[i] % n] == -1)
                {
                        count[pre[i] % n] = i;
                }
                else
                {
                        index = i;
                        cout << index - count[pre[i] % n] << "\n";
                        for (ll j = count[pre[i] % n] + 1; j <= index; j++)
                        {
                                cout << j + 1 << " ";
                        }
                        return;
                }
        }

        if (f == 1)
        {

        }
        else
                cout << "-1\n";
}

int main()
{
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifndef ONLINE_JUDGE
        //for getting input from input.txt
        freopen("input.txt", "r", stdin);
        //for writing output to output.txt
        freopen("output.txt", "w", stdout);
#endif

        ll t = 1;
        cin >> t;
        while (t--)
                solve();

        return 0;
}

ll countDigits(ll n)
{
        return floor(log10(n) + 1);
}

ll gcd (ll a, ll b)
{
        if (b == 0)
                return a;
        else
                return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
        return (a * b) / gcd(a, b);
}

bool isPrime(ll n)
{
        if (n == 1)
                return false;
        if (n == 2 || n == 3 || n == 5)
                return true;
        if (n % 2 == 0 || n % 3 == 0)
                return false;
        for (ll i = 5; i * i <= n; i = i + 6)
        {
                if (n % i == 0 || n % (i + 2) == 0)
                        return false;
        }
        return true;
}

ll power(ll x, ll n)
{
        if (n == 0)
                return 1;
        ll temp = power(x, n / 2);
        temp = temp * temp;
        if (n % 2 == 0)
                return temp;
        else
                return temp * x;

}

ll setBits(ll n)
{
        ll res = 0;
        while (n > 0)
        {
                n = (n & (n - 1));
                res++;
        }
        return res;
}

