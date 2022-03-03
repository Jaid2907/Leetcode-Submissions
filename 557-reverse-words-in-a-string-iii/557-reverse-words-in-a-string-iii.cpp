class Solution {
public:
    string reverse(string s)
    {
        int n = s.size();
        for(int i=0; i<n/2; i++)
            swap(s[i],s[n-i-1]);
        
        return s;
    }
    string reverseWords(string s) {
        
        s += ' ';
        int n = s.size();
        int start = 0;
        vector<string> v;
        string temp = "";
        string ans = "";
        for(int i=0; i<n; i++)
        {
            
            if(s[i] == ' ')
            {
                v.push_back(temp);
                temp = "";
            }
            else
                temp += s[i];
        }
        int flag = 0;
        for(auto it: v)
        {
           
            if(flag == 0)
            {
                flag = 1;
                ans += reverse(it);
            }
            else
            {
                ans += ' ';
                ans += reverse(it);
            }
           
        }
        
        return ans;
    }
    
};