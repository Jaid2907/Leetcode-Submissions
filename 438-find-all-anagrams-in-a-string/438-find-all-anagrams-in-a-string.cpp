class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map <char,int> mp,mp2;
        int p_size = p.size();
        int s_size = s.size();
        vector<int> ans;
        if(s_size < p_size)
            return ans;
        for(int i=0; i<p_size; i++)
        {
            mp[p[i]]++;
            mp2[s[i]]++;
        }
        
        if(mp == mp2)
            ans.push_back(0); 
        
        int flag = 0;
        for(int i=p_size; i<s_size; i++)
        {
            mp2[s[i-p_size]]--;
            mp2[s[i]]++;
            flag = 0;
            
            for(int i=97; i<122; i++)
            {
                if(mp[char(i)] != mp2[char(i)])
                   {
                       flag = 1;
                       break;
                   }
            }
            
            if(flag == 0)
                ans.push_back(i-p_size+1);
        }
        
        return ans;
    }
};