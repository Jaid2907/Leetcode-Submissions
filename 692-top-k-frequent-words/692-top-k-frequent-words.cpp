class Solution {
public:
    static bool compare (pair<string,int>& a, pair<string,int>& b){
        if(a.second == b.second)
            return a.first < b.first;
        
        return a.second > b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
     
        vector<string> ans;
        unordered_map<string,int> mp;
        
        for(auto &it: words){
            mp[it]++;
        }
        
        vector<pair<string,int>> v;
        
        for(auto &it: mp){
            v.push_back({it.first,it.second});
        }
        
        sort(v.begin(), v.end(), compare);
        
        for(int i = 0; i<k; i++){
            ans.push_back(v[i].first);
        }
        
        return ans;
        
    }
};