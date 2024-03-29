class Solution {
public:
    static bool compare (int a, int b){
        if(a<0 && b<0)
            return a>b;
        return a<b;
    }
    bool canReorderDoubled(vector<int>& changed) {
        
        
        
        unordered_map<int,int> mp;
        
        int n = changed.size();
        int f = 0;
       
        for(int i = 0; i<n; i++){
            mp[changed[i]]++;
        }
        sort(changed.begin(), changed.end(), compare);
        
        // for(auto it: changed){
        //     cout<<it<<" ";
        // }
        for(int i = 0; i<n; i++){
            if(mp.find(changed[i]) != mp.end()){
                if(mp.find(2*changed[i]) == mp.end()){
                    return false;
                }
                
               
                if(mp[2*changed[i]] >= mp[changed[i]]){
                    mp[2*changed[i]] -= mp[changed[i]];
                    mp.erase(changed[i]);
                    if(mp[2*changed[i]] == 0)
                        mp.erase(2*changed[i]);
                }
                else
                    return false;
               
            }
        }
        
        if(mp.empty())
            return true;
        return false;
    
    }
};