class Solution {
public:
    bool isValid (string &s){
        
        if(s[0] == '0' && s.size() > 1)
            return false;
        if(stoi(s)>=0 && stoi(s) <= 255)
        return true;
        
        return false;
    }
    void helper (int i, string& s, int n, vector<string>& ans, string& curr, int cnt){
        
        if(i >= n && cnt == 4){
            curr.pop_back();
            ans.push_back(curr);
            curr += '.';
            return;
        }
        
        string temp = "";
        
        for(int j = i; j<i+3 && j<n; j++){
            temp += s[j];
            
            if(isValid(temp)){
                curr += temp;
                curr += '.';
                
                helper(j+1,s,n,ans,curr, cnt + 1);
                
                int k = temp.size() + 1;
                
                while(k--)
                    curr.pop_back();
            }
            else
                break;
               
        }
        
        
    }
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> ans;
        string curr = "";
        int cnt = 0;
        
        helper(0,s,s.size(),ans,curr,cnt);
        
        return ans;
        
    }
};