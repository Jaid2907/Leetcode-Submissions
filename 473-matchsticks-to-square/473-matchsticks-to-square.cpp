class Solution {
public:
    bool helper (int i, vector<int>& nums, int s1, int s2, int s3, int s4, int n, unordered_map<string,bool>& mp, int sum){
        
        
         
        
        if(i == n){
            if(s1 == s2 && s2 == s3 && s3 == s4)
                return true;
            return false;
                
        }
        
        string key = to_string(i) + "*" + to_string(s1) + "*" + to_string(s2) + "*" + to_string(s3) + "*" + to_string(s4);
        
        if(mp.find(key) != mp.end())
            return mp[key];
        
        bool first = false, second = false, third = false, fourth = false;
        
        //Include in 1st
        if(s1+nums[i] <= sum/4)
        first = helper (i+1,nums,s1+nums[i],s2,s3,s4,n,mp,sum);
        
        //Include in 2nd
        if(s2+nums[i] <= sum/4 && s2 != s1)
        second = helper(i+1,nums,s1,s2+nums[i],s3,s4,n,mp,sum);
        
        //Include in 3rd
        if(s3 + nums[i] <= sum/4 && s3 != s2 && s3 != s1)
        third = helper(i+1,nums,s1,s2,s3+nums[i],s4,n,mp,sum);
        
        //Include in 4th
        if(s4 + nums[i] <= sum/4 && s4 != s3 && s4 != s2 && s4 != s1)
        fourth = helper(i+1,nums,s1,s2,s3,s4+nums[i],n,mp,sum);
        
        return mp[key] = first || second || third|| fourth;
        
        
        
    }
    bool makesquare(vector<int>& nums) {
        
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum  % 4 != 0)
            return false;
        
        unordered_map <string,bool> mp;
        sort(nums.begin(), nums.end(), greater<int>());   
        
        return helper(0,nums,0,0,0,0,nums.size(),mp, sum);
    }
};