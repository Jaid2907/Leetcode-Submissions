class Solution {
public:
    vector<int> countBits(int n) {
        
        //Using Bit dividing logic that X=Y/2 will lead to 
        // No of set bits in Y - No of set bits in X <=1
        vector<int> ans(n+1);
        ans[0] = 0;
        
        for(int i=1; i<n+1; i++)
        {
            ans[i] = ans[i/2]+i%2;
        }
        
        return ans;
    }
};