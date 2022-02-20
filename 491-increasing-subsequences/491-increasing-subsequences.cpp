class Solution {
public:
    bool isSorted(vector<int>& ds)
    {
        
        int n = ds.size();
        for(int i=1; i<n; i++)
            if(ds[i]<ds[i-1])
                return false;
        
        return true;
    }
    void findSubsequence (vector<int>& nums, int i, vector<int>& ds, set<vector<int>>& s)
    {
        
        
        
        
        if(ds.size()>=2)
        {
            if(isSorted(ds))
                s.insert(ds);
        }
        
        if( i == nums.size())
            return;
        //Pick 
        ds.push_back(nums[i]);
        findSubsequence(nums,i+1,ds,s);
        ds.pop_back();
        //Non Pick
        findSubsequence(nums,i+1,ds,s);
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> ds;
        set<vector<int>> s;
        
        findSubsequence(nums,0,ds,s);
        vector<vector<int>> ans;
        
        for(auto &it: s)
            ans.push_back(it);
        
        return ans;
        
        
        
    }
};