class Solution {
public:
    int decimalToBinary (int n){
        int num = n;
        int cnt = 0;
        
        while(num){
            num /= 2;
            cnt++;
        }
        
        return cnt;
    }
    int concatenatedBinary(int n) {
        
        long long int ans = 0;
        int mod = 1e9+7;
        for(int i = 1; i<=n; i++){
            
            int j = decimalToBinary(i);
            
            ans = ans<<j;
            ans %= mod;
            ans += i;
            ans %= mod;
            
        }
        
        return ans;
    }
};