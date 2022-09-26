class Solution {
public:
    
    int helper(int root, unordered_map<int,vector<int>>& mp, unordered_map<int,pair<int,int>>& nodes, vector<long long int>& ans, int n){
        if(mp[root].empty()){
            nodes[root].first = 0;
            nodes[root].second = 0;
            ans[root] = (n-1);
            return 1;
        }
        
        int a = 0, b = 0;
        if(mp[root].size() >= 1)
         a = helper(mp[root][0],mp,nodes,ans,n);
        if(mp[root].size() >= 2)
         b = helper(mp[root][1],mp,nodes,ans,n);
        
        nodes[root].first = a;
        nodes[root].second = b;
        if(root == 0){
            if(a == 0 && b == 0)
                ans[root] = 1;
            else if(a == 0 || b == 0)
                ans[root] = n-1;
            else
                ans[root] = a*1ll*b;
        }
        else if(a == 0 && b == 0)
            ans[root] = n-1;
        else if(a == 0)
            ans[root] = b *1ll* (n-b-1);
        else if(b == 0)
            ans[root] = a *1ll* (n-a-1);
        else
            ans[root] = a*b*1ll*(n-a-b-1);
        
        return 1 + a + b;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        
        unordered_map<int,vector<int>> mp;
        int n = parents.size();
        vector<long long int> ans(n);
        
        for(int i = 1; i<n; i++){
            mp[parents[i]].push_back(i);
        }
        for(int i = 0; i<n; i++){
            if(mp.find(i) == mp.end()){
                mp[i] = {};
            }
        }
       
        unordered_map <int,pair<int,int>> nodes;
        helper(0,mp,nodes,ans,n);
        long long int maxi = INT_MIN;
        for(int i = 0; i<n; i++){
            if(maxi < ans[i]){
                maxi = ans[i];
            }
        }
        
        int cnt = 0;
        for(auto it: ans){
            if(it == maxi)
                cnt++;
        }
        
        return cnt;
        
    }
};