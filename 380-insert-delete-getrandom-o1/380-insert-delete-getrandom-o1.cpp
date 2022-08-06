class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int,int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end())return false;
        nums.push_back(val);
        mp[val] = nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end())return false;
        if(nums.size() == 1){
            mp.erase(val);
            nums.pop_back();
            return true;
        }
        int index = mp[val];
        if(index == nums.size()-1){
            nums.pop_back();
            mp.erase(val);
            return true;
        }
        mp.erase(val);
        int prev = nums[nums.size()-1];
        nums[index] = prev;
        mp[prev] = index;
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        return nums[rand() %nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */