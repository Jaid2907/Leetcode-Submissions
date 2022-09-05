class Solution {
public:
    int helper (int n, int k){
        if(n == 1)
            return 0;
        
        if(k&1)
            return helper (n-1,k/2+1) == 0? 0 : 1;
        else
            return helper(n-1, k/2) == 0? 1 :0;
    }
    int kthGrammar(int n, int k) {
        
        return helper(n,k);
    }
};