class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string> ans;
        string push = "Push";
        string pop = "Pop";
        int cnt = 1;
        
        for(int i = 0; i<target.size(); i++){
            
            while(cnt<=n && target[i] != cnt){
                ans.push_back(push);
                ans.push_back(pop);
                cnt++;
            }             
            if(target[i] == cnt){
                ans.push_back(push);
                cnt++;
            }
        }
        
        
        return ans;
    }
};