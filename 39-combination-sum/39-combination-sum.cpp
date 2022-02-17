class Solution {
public:
    void combination(vector<vector<int>>& ans, vector<int>& ds, int target, vector<int>& candidates, int i)
    {
         if (target == 0)
        {
            ans.push_back(ds);
            return ;
        }
        if(target<0 || i == candidates.size())
        {
            return ;
        }
       
        
        //pick
        ds.push_back(candidates[i]);
        combination(ans,ds,target-candidates[i],candidates,i);
        ds.pop_back();
        //Not Pick
        combination(ans,ds,target,candidates,i+1);
        
       
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> ds;
       
        
        combination(ans,ds,target,candidates,0);
       
        
        return ans;
    }
};