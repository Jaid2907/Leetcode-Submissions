class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int freq1[26] = {0};
        int freq2[26] = {0};
        
        int m = s1.size();
        int n = s2.size();
        if(m>n)
            return false;
        for(int i=0; i<m; i++)
        {
            freq2[s2[i]-97]++;
            freq1[s1[i]-97]++;
            
        }
        int flag = 0;
        
         for(int i=0; i<26; i++)
        {
                if(freq1[i] != freq2[i])
                 {
                    flag = 1;
                    break;
                 }
        }
        
        if(flag == 0)
            return true;
        for(int i=m; i<n; i++)
        {
            flag = 0;
            freq2[s2[i]-97]++;
            freq2[s2[i-m] -97]--;
            
            for(int j=0; j<26; j++)
            {
                if(freq1[j] != freq2[j])
                {
                    flag = 1;
                    break;
                }
            }
            
            if(flag == 0)
                return true;
            
            
        }
       
        
        return false;
        
    }
};