class Solution {
public:
    bool isSubsequence(string s, string t) {
     int i = 0;
     int j = 0;
     int n = t.size();
     int m = s.size();
        
        if(m>n)
            return false;
     
        while(i<n && j<m)
        {
            if(t[i] == s[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        
        if(j == m)
            return true;
        
        return false;
    }
};