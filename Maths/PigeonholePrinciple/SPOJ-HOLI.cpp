//https://www.spoj.com/problems/HOLI/
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
 
vector<pair<ll, ll>> graph[100005];
 
 
ll n, m, k;
 
ll res = 0;
 
ll dfs(ll pre, ll x)
{
        ll ans = 1;
 
 
        for (ll i = 0; i < graph[x].size(); i++)
        {
                ll v = graph[x][i].first;
                ll wt = graph[x][i].second;
                if (pre == v)
                        continue;
                ll nodes = dfs(x, v);
                res += 2 * min(nodes, n - nodes) * wt;
                ans += nodes;
        }
 
 
        return ans;
 
}
 
void solve(ll t)
{
        cin >> n;
        res = 0;
 
        for (ll i = 1; i <= n; i++)
                graph[i].clear();
 
 
        for (ll i = 1; i <= n - 1; i++)
        {
                ll x, y, z;
                cin >> x >> y >> z;
 
                graph[x].push_back({y, z});
                graph[y].push_back({x, z});
        }
 
 
        ll ans = dfs(0, 1);
 
        cout << "Case #" << t << ": " << res << "\n";
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
        ll i = 1;
        while (i <= t)
                solve(i++);
 
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