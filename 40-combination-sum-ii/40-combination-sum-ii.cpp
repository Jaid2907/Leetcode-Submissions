class Solution {
public:
    void combination(vector<vector<int>>& ans, vector<int>& ds, int target,vector<int>& candidates, int index)
    {
         if(target == 0)
        {
           
            ans.push_back(ds);
            return;
        }
        
            for(int i = index; i<candidates.size(); i++)
            {
                if(i>index && candidates[i] == candidates[i-1])
                    continue;
                if(candidates[i]>target)
                    break;
                
            ds.push_back(candidates[i]);
            combination(ans,ds,target-candidates[i],candidates,i+1);
            ds.pop_back();
          
            }
        
            
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
       
        combination(ans,ds,target,candidates,0);
       
        
        return ans;
        
    }
};