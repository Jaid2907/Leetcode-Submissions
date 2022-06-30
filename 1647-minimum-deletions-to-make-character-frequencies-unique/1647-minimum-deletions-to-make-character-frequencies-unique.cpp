class Solution {
public:
    int minDeletions(string s) {
        
        unordered_map <int,int> mp1;
        unordered_map <char,int> mp2;
        vector<int> v;
        
        for(int i=0; i<s.size(); i++){
            mp2[s[i]]++;
        }
        for(auto it: mp2){
            v.push_back(it.second);
            mp1[it.second]++;
        }
        
        sort(v.begin(), v.end());
        int cnt = 0;
        
        for(int i=0; i<v.size(); i++){
            
            if(mp1[v[i]]>1){
                int a = v[i];
                
                while(mp1.find(v[i]) != mp1.end()){
                    cnt++;
                    v[i] -= 1;
                }
                   
            
                mp1[a]--;
                if(v[i])
                mp1[v[i]]++;
            }
        }
        
        return cnt;
        
        
    }
};