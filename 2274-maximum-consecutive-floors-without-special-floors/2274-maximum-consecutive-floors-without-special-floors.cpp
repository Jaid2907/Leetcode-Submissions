class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        
        sort(special.begin(), special.end());
        unordered_map<int,int> mp;
        for(auto it: special){
            mp[it]++;
        }
        int max_gap = INT_MIN;
        int cnt = 0;
        int prev = bottom;
        max_gap = special[0]-bottom;
        for(int i=1; i<special.size(); i++)
        {
            max_gap = max (max_gap, special[i] - special[i-1] -1);
        }
        max_gap = max (max_gap, top-special[special.size()-1]);
      
       
        return max_gap;
        
    }
};