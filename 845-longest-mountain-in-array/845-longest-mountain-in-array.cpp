class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int cnt = 0;
        int ans = 0;
        int n = arr.size();
        
        for(int i = 0; i<n; i++){
            
            if(i>0 && i+1<n && arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                cnt = 0;
                int j = i;
                while(j>0 && arr[j]>arr[j-1]){
                    cnt++;
                    j--;
                }
                j = i;
                
                while(j<n-1 && arr[j]>arr[j+1]){
                    cnt++;
                    j++;
                }
                
                ans = max(ans, cnt+1);
                    
            }
        }
        
        return ans;
    }
};