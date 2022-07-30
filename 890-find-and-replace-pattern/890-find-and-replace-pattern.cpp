class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        
        vector<string> ans;
        
        int flag = 0;
        
        for(int i = 0; i<words.size(); i++){
            
            unordered_map<char,char> mp1, mp2;
            flag = 0;
            if(pattern.size() != words[i].size()){
                continue;
            }
            
            for(int j = 0; j<words[i].size(); j++){
                
                
                if(mp1.find(pattern[j]) == mp1.end() && mp2.find(words[i][j]) == mp2.end()){
                    mp1[pattern[j]] = words[i][j];
                    mp2[words[i][j]] = pattern[j];
                   
                }
                else if(mp1.find(pattern[j]) != mp1.end() && mp2.find(words[i][j]) == mp2.end()){
                    
                    flag = 1;
                    break;
                }
                else if (mp1.find(pattern[j]) == mp1.end() && mp2.find(words[i][j]) != mp2.end()){
                    if(mp2[words[i][j]] != pattern[j]){
                        flag = 1;
                        break;
                    }
                }
                else {
                    if(mp1[pattern[j]] != words[i][j] || mp2[words[i][j]] != pattern[j]){
                        flag = 1;
                        break;
                    }
                        
                }
                       
            }
            
            if(flag == 0)
                ans.push_back(words[i]);
        }
        
        return ans;
        
        
    }
};