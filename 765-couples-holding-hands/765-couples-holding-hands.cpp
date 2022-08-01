class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        unordered_map<int,int> mp;
        
        for(int i = 0; i<row.size(); i++){
            mp[row[i]] = i;
        }
        
        int cnt =  0;
        int s = row.size();
        
        for(int i = 0; i<s; i+=2){
            
            int first = row[i];
            int second = first^1;
            
            if(row[i+1] != second){
                
                int j = mp[second];
                int prev = row[i+1];
                swap(row[i+1], row[mp[second]]);
                mp[row[i+1]] = i+1;
                mp[prev] = j;
                cnt++;
            }
            
        }
        
        return cnt;
        
        
    }
};