class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        unordered_map<int,int> mp;
        vector<int> ans;
        int n = changed.size();
        int f = 0;
        for(int i = 0; i<n; i++){
            mp[changed[i]]++;
        }
        
        for(int i = 0; i<n; i++){
            if(mp.find(changed[i]) != mp.end()){
                if(mp.find(2*changed[i]) == mp.end()){
                    f = 1;
                    break;
                }
                
                ans.push_back(changed[i]);
                mp[changed[i]]--;
                if(mp[changed[i]] == 0)
                    mp.erase(changed[i]);
                
                mp[2*changed[i]]--;
                if(mp[2*changed[i]] == 0)
                    mp.erase(2*changed[i]);
            }
        }
        
        if(mp.empty() && f == 0){
            return ans;
        }
        ans.clear();
        return ans;
    }
};