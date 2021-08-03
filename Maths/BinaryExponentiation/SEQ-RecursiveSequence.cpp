//https://www.spoj.com/problems/SEQ/
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
const ll MOD = 1000000000;

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

vector<vector<ll>> mutiply(vector<vector<ll>> x, vector<vector<ll>>y)
{
        ll m = x.size(), n = y[0].size();
        vector<vector<ll>> ans(m, vector<ll>(n, 0));
        for (int i = 0; i < m; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        ans[i][j] = 0;
                        for (int k = 0; k < m; k++)
                        {
                                ans[i][j] = (ans[i][j]%MOD + ((x[i][k]%MOD) * (y[k][j]%MOD))%MOD)%MOD;
                        }
                }
        }

        return ans;
}

vector<vector<ll>> BinPower(vector<vector<ll>> p, ll m)
{
        ll n = p.size();

        vector<vector<ll>> res(n,vector<ll>(n,0));

        for (ll i = 0; i < n; i++)
        {
                for (ll j = 0; j < n; j++)
                {
                        if (j == i)
                                res[i][j] = 1;
                        else
                                res[i][j] = 0;
                }
        }

        while (m > 0)
        {
                if (m % 2 != 0)
                        res = mutiply(p, res);
                m /= 2;
                p = mutiply(p, p);
        }

        return res;
}


void solve()
{
        ll k;
        cin >> k;

        vector<ll> b(k, 0);

        for (ll i = 0; i < k; i++)
                cin >> b[i];

        vector<ll> c(k, 0);

        for (ll i = 0; i < k; i++)
                cin >> c[i];

        ll n;
        cin >> n;

        if (n <= k)
        {
                cout << b[n - 1] << "\n";
                return;
        }

        vector<vector<ll>> ans(k, vector<ll>(1, 0)), matrix(k, vector<ll>(k, 0)), fact(k, vector<ll>(1, 0));

        for (ll i = 0; i < k; i++)
                fact[i][0] = b[k - i - 1];

        for (ll i = 0; i < k; i++)
        {
                for (ll j = 0; j < k; j++)
                {
                        if (i == 0)
                                matrix[i][j] = c[j];
                        else if ((i - 1) == j)
                                matrix[i][j] = 1;
                        else matrix[i][j] = 0;

                }
        }
        
        

        ans = mutiply(BinPower(matrix, n - k), fact);
        
        //  for (ll i = 0; i < k; i++)
        // {
        //         for (ll j = 0; j < k; j++)
        //         {
        //                 cout <<    ans[i][j] << " ";

        //         }
                
        //         cout << "\n";
        // }

        cout << ans[0][0] << "\n";
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

