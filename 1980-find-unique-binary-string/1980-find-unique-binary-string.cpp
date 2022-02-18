class Solution {
public:
    void findBinary(int i, int n,unordered_map <string,int>& mp, string& s, string& ans)
    {
        
        if(i==n)
        {
            if(mp.find(s) == mp.end())
                ans = s;
            
            return;
        }
        if(s.size() == n)
            return ;
        
        s.push_back('0');
        findBinary(i+1,n,mp,s,ans);
        s.pop_back();
        s.push_back('1');
        findBinary(i+1,n,mp,s,ans);
        s.pop_back();
        
        
        
    }
    string findDifferentBinaryString(vector<string>& nums) {
        
        unordered_map <string,int> mp;
        int n = nums.size();
        string s = "";
        string ans = "";
        for(int i=0; i<n; i++)
            mp[nums[i]]++;
       
        
        findBinary(0,n,mp,s,ans);
        return ans;
        
    }
};