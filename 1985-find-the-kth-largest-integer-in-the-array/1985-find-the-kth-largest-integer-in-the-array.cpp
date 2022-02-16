class Solution {
public:
    static bool compare(string a, string b)
    {
        if(a.size()<b.size())
            return true;
        else if(a.size()>b.size())
            return false;
        int n = a.size();
        for(int i=0; i<n; i++)
        {
            if(a[i]<b[i])
                return true;
            else if(a[i]>b[i])
                return false;
                
        }
        
        return false;
        
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),compare);
        
        int n = nums.size();
        return nums[n-k];
    }
};