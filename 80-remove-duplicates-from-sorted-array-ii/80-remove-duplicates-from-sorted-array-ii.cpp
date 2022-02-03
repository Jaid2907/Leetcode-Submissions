class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        map<int,int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(mp[nums[i]]<2)
                mp[nums[i]]++;
        }
        int i=0;
        for(auto& it: mp)
        {
            while(it.second--)
            {
                nums[i++] = it.first;
            }
        }
        
        return i;
        
    }
};