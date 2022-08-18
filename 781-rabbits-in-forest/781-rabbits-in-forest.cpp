class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int,int> mp;
        int cnt = 0;
        
        for(int i = 0; i<n; i++){
            if(answers[i] != 0 && mp.find(answers[i]) != mp.end()){
                if(mp[answers[i]] < answers[i]+1){
                    mp[answers[i]]++;
                  continue;   
                }
                else{
                    mp.erase(answers[i]);
                }
               
            }
            mp[answers[i]]++;
            cnt += answers[i]+1;
        }
        
        return cnt;
    }
};