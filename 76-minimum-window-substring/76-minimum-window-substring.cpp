class Solution {
public:
    string minWindow(string s, string p) {
        int len = INT_MAX;
        // unordered_map <char, int> mp_s, mp_p;
        int freq_s[256] = {0};
        int freq_p[256] = {0};
        
        int start = INT_MAX, end = INT_MIN;
        for(int i = 0; i<p.size(); i++)
            freq_p[p[i]]++;
        
        int j = 0;
        
        for(int i = 0; i<s.size(); i++){
            
            freq_s[s[i]]++;
            int flag = 0;
            
            
            
            for(int i = 0; i<=255; i++){
                if(freq_s[i]< freq_p[i]){
                    flag = 1;
                    break;
                }
            }
            
            if(flag == 0){
                while(j<=i){
                if(freq_s[s[j]] > freq_p[s[j]]){
                    freq_s[s[j]]--;
                    j++;
                }
                else
                 break;
            }
                if(len > i-j+1){
                    start = j;
                    end = i;
                    len = i-j+1;
                }
            }
            
        }
        
        if(end>=start)
        return s.substr(start, end-start+1);
        return "";
    }
};