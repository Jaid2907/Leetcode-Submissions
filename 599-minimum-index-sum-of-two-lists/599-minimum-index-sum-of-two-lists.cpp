class Solution {
public:

    
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map <string, int> mp;
        vector<string> ans;
        string str;
        int mini_index_sum = INT_MAX;
        
        for(int i=0; i<list1.size(); i++){
            mp[list1[i]] = i;
        }
        
        for(int i=0; i<list2.size(); i++){
            if(mp.find(list2[i]) != mp.end()){
                if(mp[list2[i]] + i < mini_index_sum ){
                    mini_index_sum = mp[list2[i]] + i;
                }
            }
        }
        
        for(int i=0; i<list2.size(); i++){
            if(mp.find(list2[i]) != mp.end()){
                if(mp[list2[i]] + i == mini_index_sum)
                    ans.push_back(list2[i]);
            }
        }
        
        return ans;
    }
};