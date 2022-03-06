class Solution {
public:
    int countOrders(int n) {
        
        long long int ans = 1;
        int mod = 1e9+7;
        
        for(int i=1; i<=n; i++)
        {
            ans = ( (ans%mod) * (i%mod) )%mod;
        }
        
        for(int i=1; i<=2*n-1; i+=2)
        {
            ans = ( (ans%mod) * (i%mod) ) %mod;
        }
        
        return ans;
    }
};