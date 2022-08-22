class Solution {
public:
    bool isPowerOfFour(int n) {
        long long int curr = 1;
        
        while(curr <= n){
            
            if(n == curr)
                return true;
            curr *= 4;
        }
        return false;
    }
};