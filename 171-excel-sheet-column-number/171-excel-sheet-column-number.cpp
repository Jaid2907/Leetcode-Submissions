class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int j = n-1;
        int ans = 0;
        long long int pow = 1;
        while(j>=0)
        {
            ans += (columnTitle[j]-64)*pow;
            pow *= 26;
            j--;
        }
        
        return ans;
    }
};