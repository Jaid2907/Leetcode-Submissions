class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        
        int n = s.size();
        
        unordered_map<int,vector<int>> mp;
        vector<int> freq(26,0);
        mp[-1] = freq;
        
        for(int i = 0; i<n; i++){
            freq[s[i]-97]++;
            mp[i] = freq;
        }
        
        int m = queries.size();
        vector<bool> ans(m);
        
        for(int i = 0; i<m; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            
            vector<int> freq(26,0);
            int odd_cnt = 0;
            
            for(int j = 0; j<26; j++){
                freq[j] = mp[r][j] - mp[l-1][j];
                if(freq[j]&1)
                    odd_cnt++;
            }
            
            
            
            if(odd_cnt/2 > k){
                ans[i] = false;
            }
            else{
                ans[i] = true;
            }
            
            
        }
        
        return ans;
        
        
        
    }
};