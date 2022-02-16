#include <bits/stdc++.h>
vector<int> hash_map(1e6+100);
class MyHashSet {
    private:
        
public:
    
    MyHashSet() {
        fill(hash_map.begin(),hash_map.end(),-1);
    }
    
    void add(int key) {
        hash_map[key] = key;
        
    }
    
    void remove(int key) {
        hash_map[key] = -1;
        
    }
    
    bool contains(int key) {
        
        if(hash_map[key] != -1)
            return true;
        
        return false;
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */