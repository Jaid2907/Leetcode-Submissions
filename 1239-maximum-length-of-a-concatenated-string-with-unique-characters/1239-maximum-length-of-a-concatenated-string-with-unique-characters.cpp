class Solution {
public:
    int ans = 0;
    bool canBePicked (string& s, vector<int>& freq){
        int n = s.size();
        for(int i = 0; i<n; i++){
            freq[s[i]-97]++;
            
            if(freq[s[i]-97] > 1)
                return false;
        }
        
        ans = max(ans, accumulate(freq.begin(),freq.end(),0));
        return true;
    }
    void helper (vector<string>& arr, int i, vector<int> freq){
        if(i == arr.size()){
            return ;
        }
        
        int pick = 0, nonPick = 0;
        vector<int> prev_freq = freq;
        if(canBePicked(arr[i],freq)){
         helper(arr,i+1,freq);
        }
        
        freq = prev_freq;
        helper(arr,i+1,freq);
        
    }
    int maxLength(vector<string>& arr) {
        
        vector<int> freq(26,0);
        helper(arr,0,freq);
        
        return ans;
    }
};