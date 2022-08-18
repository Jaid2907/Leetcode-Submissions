class Solution {
public:
    static bool compare(pair<int,int>& a, pair<int,int>& b){
        return a.second < b.second;
    }
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        
        for(auto it: arr){
            mp[it]++;
        }
        
        vector<pair<int,int>> v;
        
        for(auto it: mp){
            v.push_back({it.first, it.second});
        }
        
        sort(v.begin(), v.end(),compare);
        
        int j = v.size()-1;
        int n = arr.size();
        int half = n/2;
        int cnt = 0;
        
        while(n>half && j>=0){
            
            n -= v[j].second;
            cnt++;
            j--;
        }
        
        return cnt;
    }
};