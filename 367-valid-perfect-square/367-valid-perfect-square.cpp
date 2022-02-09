class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 0)
            return true;
        long long int low = 1, high = num, mid;
        
        while(low<high)
        {
            mid = (low+high)/2;
            
            if(1ll*mid*mid==num)
                return true;
            if(1ll*mid*mid>num)
                high= mid-1;
            else
                low = mid+1;
        }
        
        if(1ll*low*low == num || 1ll*high*high == num)
            return true;
        return false;
    }
};