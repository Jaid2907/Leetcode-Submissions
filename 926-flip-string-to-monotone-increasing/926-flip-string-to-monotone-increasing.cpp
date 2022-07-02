class Solution {
public:
    int minFlipsMonoIncr(string s) {
     
        int n = s.size();
        if(n == 1)
            return 0;
        vector<int> prefix_1(n+1,0);
        vector<int> prefix_0(n+1,0);
        
        int cnt_0 = 0, cnt_1 = 0;
        
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                cnt_1++;
            }
            prefix_1[i] = cnt_1;
        }
        
        for(int i=n-1; i>=0; i--){
            if(s[i] == '0'){
                cnt_0++;
            }
            
            prefix_0[i] = cnt_0;
        }
        
        int ans = prefix_0[1];
        
        for(int i=1; i<n; i++){
            
            ans = min (ans, prefix_0[i+1] + prefix_1[i-1]);
           
        }
        
        return ans;
        

    }
};