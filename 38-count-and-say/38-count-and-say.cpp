class Solution {
public:
    string count (int n, string s, int i)
    {
        if(i==n)
            return s;
        
        string str;
        int cnt = 0;
        for(int i=0; i<s.size(); i++)
        {
            cnt = 0;
            int a = s[i]-48;
            cnt++;
            while(i+1<s.size() && s[i] == s[i+1])
            {
                i++;
                cnt++;
            }   
            
            str += to_string(cnt);
            str += to_string(a);
        }
        
        
        return count(n,str,i+1);
        
    }
    string countAndSay(int n) {
        
        return count(n,"1",1);
        
    }
};