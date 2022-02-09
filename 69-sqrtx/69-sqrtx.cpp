class Solution {
public:
    int mySqrt(int x) {
        long long int i = 1;
        int ans;
        if(x==0)
            return 0;
    while(true)
    {
        if(1ll * i*i>x)
            break;
        ans = i;
        i++;
    }
        
        return ans;
    }
};