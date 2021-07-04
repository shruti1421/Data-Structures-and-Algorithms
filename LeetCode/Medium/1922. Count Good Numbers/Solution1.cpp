#define ll long long int
const ll MOD = 1e9 + 7;

class Solution {
public:
    
  
 
// Returns modulo exponentiation for two numbers
// represented as long long int. It is used by
// powerStrings(). Its complexity is log(n)
ll powerLL(ll x, ll n)
{
    ll result = 1;
    while (n) {
        if (n & 1)
            result = result * x % MOD;
        n = n / 2;
        x = x * x % MOD;
    }
    return result;
}
 
// Returns modulo exponentiation for two numbers
// represented as strings. It is used by
// powerStrings()
ll powerStrings(string sa, string sb)
{
    // We convert strings to number
 
    ll a = 0, b = 0;
 
    // calculating  a % MOD
    for (int i = 0; i < sa.length(); i++)
        a = (a * 10 + (sa[i] - '0')) % MOD;
 
    // calculating  b % (MOD - 1)
    for (int i = 0; i < sb.length(); i++)
        b = (b * 10 + (sb[i] - '0')) % (MOD - 1);
 
    // Now a and b are long long int. We
    // calculate a^b using modulo exponentiation
    return powerLL(a, b);
}
    
    // Returns (a * b) % mod
long long moduloMultiplication(long long a,
                            long long b,
                            long long mod)
{
    long long res = 0; // Initialize result
 
    // Update a if it is more than
    // or equal to mod
    a %= mod;
 
    while (b)
    {
        // If b is odd, add a with result
        if (b & 1)
            res = (res + a) % mod;
 
        // Here we assume that doing 2*a
        // doesn't cause overflow
        a = (2 * a) % mod;
 
        b >>= 1; // b = b / 2
    }
 
    return res;
}
    
    int countGoodNumbers(long long n) {
   
        
        if(n%2==0)
        {
            n=(n/2);
            
            string str= to_string(n);  
            string str2= to_string(20);  
            
            int res=powerStrings(str2,str);
            
            return res;
        }
        
        n=n/2;
        
        if(n>0)
        {
            
            
            string str= to_string(n);  
            string str2= to_string(20);  
            
            int res=powerStrings(str2,str);
            
            return moduloMultiplication(res%MOD,5,MOD) ;
        }
        else
            return 5;
        
    }
};
