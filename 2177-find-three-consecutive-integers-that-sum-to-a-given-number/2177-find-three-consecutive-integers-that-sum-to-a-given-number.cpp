class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        if(num%3 != 0)
            return ans;
        
        long long x = num/3;
        ans = {x-1,x,x+1};
        return ans;
    }
};