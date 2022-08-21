class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
     
        int n = shifts.size();
        vector<long long int> prefix(n,0);
        long long int cnt = 0;
        
        for(int i = n-1; i>=0; i--){
            cnt += shifts[i];
            prefix[i] = cnt;
        }
        
        for(int i = 0; i<n; i++){
            s[i] = (((s[i]-'a' + prefix[i])%26 + 26)%26 + 'a');
        }
        
        return s;
    }
};