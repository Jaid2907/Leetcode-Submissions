class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        int cnt = 0;
        int ans = 0;
        int l = 0;
        int r = 0;
        for(int i=0; i<n; i++){
            
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = i;
                r = i;
            }
            else{
                int k = l;
                l = mp[s[i]]+1;
                while(k<=mp[s[i]])
                    mp.erase(s[k++]);
                
                r=i;
                mp[s[i]] = i;
            }
           
            if(l<n && r<n)
            ans = max(ans,r-l+1);
        }
        
        return ans;
    }
};