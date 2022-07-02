class Solution {
public:
    int minFlipsMonoIncr(string s) {
     
        int n = s.size();
        if(n == 1)
            return 0;
        int cnt_1 = 0, cnt_0  = 0;
        
        
        for(int i=0; i<n; i++){
            if(s[i] == '0')
                cnt_0++;
        }
        
        int ans = cnt_0;
        for(int i=0; i<n; i++){
            
            if(s[i] == '0')
                cnt_0--;
             
            
            ans = min (ans,cnt_1 + cnt_0);
            if(s[i] == '1')
                cnt_1++;
           
           
        }
        
        return ans;
        

    }
};