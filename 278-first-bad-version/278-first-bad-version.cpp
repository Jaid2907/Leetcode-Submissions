// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n==1 && isBadVersion(1))
            return 1;
        int low = 1;
        int high = n;
        int mid,ans;
        
        while(low<=high)
        {
            mid = low + (high-low)/2 ;
            bool a = isBadVersion(mid);
            if(!a)
            {
                low = mid+1;
            }
            else
            {   ans = mid;
                high = mid-1;
            }
        }
        
        return ans;
    }
};