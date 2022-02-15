class Solution {
public:
    void combination (int n, int k, int cnt, vector<vector<int>>& ans, vector<int>& ds, int index)
    {
        if(cnt == k)
        {
            ans.push_back(ds);
            return ;
        }
     
        for(int i=index; i<=n; i++)
        {
                ds.push_back(i);
                combination(n,k,cnt+1,ans,ds,i+1);
                ds.pop_back();
            
            
        }
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> ds;
        vector<vector<int>> ans;
        
        combination(n,k,0,ans,ds,1);
        
       
        
        return ans;
        
    }
};