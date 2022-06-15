class Solution {
public:
    static bool compare(string a, string b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
     
        int n = words.size();
        unordered_map <string, int> dp;
        
        sort(words.begin(),words.end(),compare);
        for(auto it: words){
            cout<<it<<" ";
        }
        cout<<endl;
        int res = 0;
        
        for(auto it: words){
            
            for(int i=0; i<it.size(); i++){
                string prev = it.substr(0,i) + it.substr(i+1);
                dp[it] = max(dp[it], dp.find(prev) == dp.end()?0:1+dp[prev]);
            }
            res = max(res,dp[it]);
        }
        
        
        return res+1;
        
        
       
        
    }
};