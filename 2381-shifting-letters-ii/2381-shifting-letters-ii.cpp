class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = shifts.size();
        vector<int> v(s.size()+1,0);
        
        for(int i = 0; i<n; i++){
            if(shifts[i][2] == 0){
                v[shifts[i][0]] -= 1;
                v[shifts[i][1] + 1] += 1;
            }
            else{
                v[shifts[i][0]] += 1;
                v[shifts[i][1] + 1] -= 1;
            }
        }
        
        
        for(int i = 1; i<s.size(); i++){
            v[i] += v[i-1];
        }
        
        for(int i = 0; i<s.size(); i++){
            s[i] = ((((s[i] - 'a' + v[i]) %26 ) + 26)% 26 + 'a');
        }
        
        return s;
    }
};