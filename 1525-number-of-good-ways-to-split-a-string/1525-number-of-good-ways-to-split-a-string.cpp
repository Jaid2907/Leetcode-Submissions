class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        int cnt_distinct = 0;
        vector<int> forward (n,0);
        vector<int> backward (n,0);
        unordered_map <char,int> mp;
        
        for(int i=0; i<n; i++){
            if(mp.find(s[i]) != mp.end()){
                forward[i] = cnt_distinct;
            }
            else{
                mp[s[i]]++;
                cnt_distinct++;
                forward[i] = cnt_distinct;
            }
        }
        
        mp.clear();
        cnt_distinct = 0;
        
        for(int i=n-1; i>=0; i--){
            if(mp.find(s[i]) != mp.end()){
                backward[i] = cnt_distinct;
            }
            else
            {   mp[s[i]]++;
                cnt_distinct++;
                backward[i] = cnt_distinct;
            }
        }
        int ans = 0;
        
        for(int i=0; i<n-1; i++){
            if(forward[i] == backward[i+1])
                ans++;
        }
        return ans;
        
        
        
    }
};