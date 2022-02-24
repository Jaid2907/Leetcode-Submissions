class Solution {
public:
    int trailingZeroes(int n) {
     
        int cnt = 0;
        int pow = 5;
        while(n/pow)
        {
            cnt += n/pow;
            pow *= 5;
        }
        
        return cnt;
    }
};