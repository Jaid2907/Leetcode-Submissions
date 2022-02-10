class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> v(n);
        int a = 0;
        for(int i=0; i<n; i++)
        {
            a = a^arr[i];
            v[i] = a;
        }
        
        vector<int> ans;
        n = queries.size();
        for(int i=0; i<n; i++)
        {
            if(queries[i][0] != 0)
            ans.push_back(v[queries[i][1]] ^ v[queries[i][0]-1]);
                else
            ans.push_back(v[queries[i][1]]);
        }
        
        return ans;
    }
};