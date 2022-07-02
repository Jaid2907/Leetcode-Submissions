class Solution {
public:
    static bool compare (vector<int>& a, vector<int>& b){
        if(a[0] == b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    static bool compare2 (pair<int,int>& a, pair<int,int>& b){
        return a.first<b.first;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
        sort (items.begin(), items.end(), compare);
        
        vector<int> ans(queries.size(), 0);
        vector<pair<int,int>> q;
        
        for(int i=0; i<queries.size(); i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end(),compare2);
        int curr = 0;
        int maxi = INT_MIN;
        
        // for(auto it: items){
        //     cout<<"["<<it[0]<<" "<<it[1]<<"]"<<" ";
        // }
        
        for(int i=0; i<q.size(); i++){
            
            while( curr<items.size() && items[curr][0]<= q[i].first){
                maxi = max(maxi,items[curr][1]);
                curr++;
                
            }
            
            // if(curr<items.size() && items[curr][0] == queries[i])
            //     maxi = max(maxi,items[curr][1]);
            // cout<<i<<endl;
            ans[q[i].second] = maxi != INT_MIN? maxi:0 ;
            
        }
        
        return ans;
    }
};