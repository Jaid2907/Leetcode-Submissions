class Solution {
public:
    char findTheDifference(string s, string t) {
     
        vector<int> freq(26,0);
        
        for(int i=0; i<t.size(); i++)
            freq[t[i]-97]++;
        for(int i=0; i<s.size(); i++)
            freq[s[i]-97]--;
        
        
        for(int i=0; i<26; i++)
        {
           if(freq[i] == 1)
               return char(i+97);
        }
        
        return 'a';
    }
};