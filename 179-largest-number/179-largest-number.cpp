
class Solution {
public:
    static bool  compare(string a, string b)
    {
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
     
        vector<string> v;
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            string s = to_string(nums[i]);
            // reverse(s.begin(),s.end());
            v.push_back(s);
        }
        sort(v.begin(),v.end(),compare);
        string ans = "";
        for(auto &it: v)
        {
            // reverse(it.begin(),it.end());
            ans += it;
        }
        while(ans[0] == '0')
            ans.pop_back();
        if(ans.size() == 0)
            ans += '0';
        return ans;
            
    }
};