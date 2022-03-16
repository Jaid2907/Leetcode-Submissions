class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        unordered_map<char,int> mp;
        int max_vow = INT_MIN;
        int vow_cnt = 0;
        
        for(int i=0;i<k; i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                mp[s[i]]++;
                vow_cnt++;
            }
        }
        
        max_vow = max(max_vow,vow_cnt);
        
        
        for(int i=k; i<n; i++)
        {
            int j = i-k;
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
            {
                mp[s[j]]--;
                vow_cnt--;
            }
            
               if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                mp[s[i]]++;
                vow_cnt++;
            }
            
            max_vow = max(max_vow,vow_cnt);
        }
        
        return max_vow;
    }
};