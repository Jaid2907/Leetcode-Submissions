class Solution {
public:
    bool isPalindrome(string& s){
        
        int n = s.size();
        
        for(int i = 0; i<n/2; i++){
            if(s[i] != s[n-i-1])
                return false;
        }
        
        return true;
    }
    void helper (int i,int n, string& s, vector<vector<string>>& ans, vector<string>& ds){
        if(i == n){
            ans.push_back(ds);
            return ;
        }
        
        for(int j = i; j<n; j++){
            string str = s.substr(i,j-i+1);
            if(isPalindrome(str)){
                ds.push_back(str);
                helper(j+1,n,s,ans,ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        int n = s.size();
        
        helper(0,n,s,ans,ds);
        
        return ans;
    }
};