class FindSumPairs {
public:
    vector<int> nums1, nums2;
    int n, m;
    unordered_map<int,int> mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
     this->nums1 = nums1;
     this->nums2 = nums2;
     n = nums1.size();
     m = nums2.size();
        
     for(int i=0; i<m; i++)
        mp[nums2[i]]++;
        
    }
    
    void add(int index, int val) {
        mp[nums2[index]]--;
        nums2[index] += val;
        mp[nums2[index]]++;
        
    }
    
    int count(int tot) {
        
        int cnt = 0;
       
        for(int i=0; i<n; i++)
        {
            if(mp.find(tot-nums1[i]) != mp.end())
                cnt+=mp[tot-nums1[i]];
        }
        return cnt;
        
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */