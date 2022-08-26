struct compare{
    bool operator()(pair<int,string> a,  pair<int,string> b){
        
        if(a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
};


class FoodRatings {
public:
    map<string, set<pair<int,string>> > cuisine_map;
    map <string, pair<string,int>> food_map;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i<n; i++){
            cuisine_map[cuisines[i]].insert(make_pair(-ratings[i], foods[i]));
            food_map[foods[i]].first = cuisines[i];
            food_map[foods[i]].second = ratings[i];
            
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food_map[food].first;
        int rating = food_map[food].second;
        
        cuisine_map[cuisine].erase({-rating, food});
        cuisine_map[cuisine].insert({-newRating, food});
        food_map[food].second = newRating;
    }
    
    string highestRated(string cuisine) {
     return cuisine_map[cuisine].begin()->second;   
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */