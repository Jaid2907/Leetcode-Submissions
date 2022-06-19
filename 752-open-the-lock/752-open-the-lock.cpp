class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
     
      
        unordered_map<string,int> mp;
        for(auto it: deadends){
            mp[it]++;
        }
        
        if(mp.find("0000") != mp.end())
            return -1;
        
        if(target == "0000")
            return 0;
        queue<string> q;
        q.push("0000");
        int ans = 0;
        
        while(!q.empty()){
            
            int size = q.size();
            
            if(size)
                ans++;
            while(size--){
                auto lock = q.front();
                q.pop();
                
                for(int i=0; i<4; i++){
                    
                    char a = lock[i];
                    char temp = lock[i];
                    
                    a += 1;
                    if(a == 58)
                        a = 48;
                    
                    lock[i] = a;
                    
                    if(lock == target)
                        return ans;
                    
                    if(mp.find(lock) == mp.end()){
                        q.push(lock);
                        mp[lock]++;
                    }
                   
                    
                    a = temp;
                    a -= 1;
                    if(a == 47)
                        a = 57;
                    lock[i] = a;
                    
                    if(lock == target)
                        return ans;
                    
                    if(mp.find(lock) == mp.end()){
                        q.push(lock);
                        mp[lock]++;
                    }
                    
                    lock[i] = temp;
                }
                    
            }
        }
        
        return -1;
    }
};