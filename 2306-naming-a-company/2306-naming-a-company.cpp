class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        
        long long int ans = 0;
        unordered_map <string, bool> mp;
        
        for(auto it: ideas){
            mp[it] = true;
        }
        int n = ideas.size();
        vector<vector<int>> v (26, vector<int>(26,0));
        
        for(int i=0; i<n; i++){
            
            char a = ideas[i][0];
            string str = ideas[i];
            
            for(char j = 'a'; j<='z'; j++){
                str[0] = j;
                
                if(mp.find(str) == mp.end())
                    v[a-97][j-97]++;
            }
        }
        
        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++)
            {
                
                
                if(v[i][j] && v[j][i])
                {   
                    ans += v[i][j] * v[j][i];
                }
           
            }
          
        }
        
        return ans;
        
    }
};