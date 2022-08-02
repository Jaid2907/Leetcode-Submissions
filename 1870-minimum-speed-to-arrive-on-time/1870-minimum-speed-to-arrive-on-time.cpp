class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        //Binary search
        int n = dist.size();
        int low = 1;
        int high = 1e9;
        int mid;
        int ans = -1;
        while(low<=high){
            
            mid = (low + high)/2;
            double sum = 0;
            
            for(int i = 0; i<n; i++){
                
                if(i == n-1){
                    sum += dist[i]/double(mid);
                    continue;
                }
                sum += ceil(dist[i]/double(mid));
            }
            
            if(sum <= hour){
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;    
            }
        }
        
        return ans;
        
    }
};