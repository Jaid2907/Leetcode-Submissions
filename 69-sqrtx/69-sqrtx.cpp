class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1)
            return x;
       long long int low = 1;
       long long int high = x;
        long long int mid;
        while(high-low>1)
        {
            mid = (low+high)/2;
            if(1ll*mid*mid>x)
            {
                high = mid;
            }
            else if(1ll*mid*mid<x)
            {
                low = mid;
            }
            else
                break;
        }
        
        if(1ll*mid*mid<=x)
            return mid;
        if(1ll*low*low<=x)
            return low;
        return high;
    }
};