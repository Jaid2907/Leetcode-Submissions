class Solution {
public:

    int maxScoreSightseeingPair(vector<int>& values) {
       pair<int,int> p = {values[0],0};
        
        int n = values.size();
        int max_score = 0;
        
        for(int i=1; i<n; i++)
        {   
            max_score = max(max_score, values[i] + values[p.second] - abs(i-p.second));
            if(values[i]>=p.first)
            {
                p.first = values[i];
                p.second = i; 
            }
            p.first--;
            
            
        }
        
        return max_score;
    }
};