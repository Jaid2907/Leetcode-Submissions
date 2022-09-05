class Solution {
public:
    int power(long long x, long long  int y, long long  p)
{
    int res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
    int countGoodNumbers(long long n) {
        if(n == 1)
            return 5;
       
        int mod = 1e9+7;
        int ans = 0;
        ans =  (power(5,ceil(n/2.0),mod)%mod *1ll* power(4,n/2,mod)%mod)%mod;
       
        
        return ans;
        
    }
};