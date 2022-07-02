class Solution {
public:
    static bool compare(pair<int,int>& a, pair<int,int>& b){
        
        if(a.first == b.first)
            return a.second < b.second;
        
        return a.first<b.first;
    }
    int getPower (int n, unordered_map<int,int>& mp){
        
        int cnt = 0;
        int orig = n;
        
        while(n!=1){
            
            if(mp.find(n) != mp.end())
                return mp[orig] = cnt+mp[n];
            
            if(n%2 == 0){
                n /= 2;
                cnt++;
            }
            else{
                n = n*3+1;
                cnt++;
            }
        }
        
        return mp[orig] = cnt;
        
    }
    int getKth(int lo, int hi, int k) {
    
        vector<pair<int,int>> ans;
        
        unordered_map<int,int> mp;
        
        for(int i=lo; i<=hi; i++){
            
            ans.push_back({getPower(i,mp),i});
        }
        
        sort(ans.begin(), ans.end(), compare);
        
       
        return ans[k-1].second;
    }
};