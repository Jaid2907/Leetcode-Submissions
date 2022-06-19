class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        queue<string> q;
        q.push(start);
        unordered_map<string,int> mp;
        int ans = 0;
        mp[start]++;
        while(!q.empty()){
            
            int size = q.size();
            if(size)
                ans++;
            while(size--){
                 auto node = q.front();
                 q.pop();
            
                
                for(int i=0; i<bank.size(); i++){
                    int cnt = 0;
                    if(mp.find(bank[i]) == mp.end())
                    for(int j=0; j<8; j++){
                        if(node[j] != bank[i][j])
                            cnt++;
                }
                
                if(cnt == 1 ){
                    if(bank[i] == end)
                    return ans;
                    mp[bank[i]]++;
                    q.push(bank[i]);
                }
                    
            }
        }
           
        }
        
        return -1;
    }
};