class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        int n = edges.size();
        unordered_map<int,int> mp;
        
            for(int j=0; j<n; j++)
            {
               mp[edges[j][0]]++;
               mp[edges[j][1]]++;
                    
            }
            
            for(auto it: mp)
            {
                if(it.second == n)
                    return it.first;
            }
           
        
        
        return 0;
    }
};