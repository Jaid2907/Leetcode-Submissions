class Solution {
public:
    static bool compare (pair<int,int>& a, pair<int,int>& b){
        if(a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        
        int n = restaurants.size();
        vector<pair<int,int>> ans;
        
        for(int i = 0; i<n; i++){
            
            int id = restaurants[i][0];
            int rating = restaurants[i][1];
            int curr_veganFriendly = restaurants[i][2];
            int price = restaurants[i][3];
            int distance = restaurants[i][4];
            
            if((!veganFriendly || curr_veganFriendly == veganFriendly) && price <= maxPrice && distance <= maxDistance){
                ans.push_back({rating,id});
            }
        }
        
        sort(ans.begin(), ans.end(), compare);
        
        vector<int> final_ans;
        
        for(int i = 0; i<ans.size(); i++){
            final_ans.push_back(ans[i].second);
        }
        
        return final_ans;
    }
};