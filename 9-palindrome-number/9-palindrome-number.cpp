class Solution {
public:
    bool isPalindrome(int x) {
         long long int n=x;
        long long int s=0;
        
        if(x<0)
            return false;
        while(n)
        {
            s=s*10+n%10;
            
            n/=10;
        }
        if(s==x)
            return true;
        return false;
    }
};