class Solution {
public:
    int getLucky(string s, int k) {
        
        int n = s.size();
        unordered_map <char,int> mp;
        string dup;
        int j = 1;
        for(char i = 'a'; j<27; i++,j++)
            mp[i] = j;
        
        for(int i=0; i<n; i++)
        {
            dup += to_string(mp[s[i]]);
        }
        s =dup;
        int sum = 0;
        cout<<s<<endl;
        while(k--)
        {
            for(int i=0; i<s.size(); i++)
                sum += s[i]-48;
            s = to_string(sum);
            sum = 0;
        }
        return stoi(s);
    }
};