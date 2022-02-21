class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0;
        int t = 32;
        while(t--)
        {
            if( (x ^ y)%2 != 0)
                cnt++;
            
            x = x>>1;
            y = y>>1;
        }
        
        return cnt;
    }
};