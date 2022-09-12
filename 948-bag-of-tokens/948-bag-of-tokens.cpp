class Solution {
public:
    static bool compare (int a, int b){
        return a<b;
        
    }   
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        
        sort(tokens.begin(), tokens.end(), compare);
        int i = 0, j = n-1;
        int score = 0;
        int ans = 0;
        
        while(i<=j){
         
            if(tokens[i] <= power){
                score++;
                power -= tokens[i];
                i++;
            }
            else if(score >=1){
                power += tokens[j];
                score--;
                j--;
            }
            else
                break;
       
            ans = max(score, ans);
        }
        return ans;
    }
};