class Solution {
public:
    bool binary_search (int low, int high, int target){
        
        int mid;
        
        while(low<=high){
            mid = low + (high-low)/2;
            // cout<<mid*mid<<endl;
            if((mid*mid) == target)
                return true;
            if((mid*mid) > target)
                high = mid-1;
            if((mid*mid) < target)
                low = mid + 1;
        }
        
        return false;
    }
    bool judgeSquareSum(int c) {
        
        int upper_bound = sqrt(c);
        // cout<<upper_bound<<endl;
        
        for(int i = 0; i<=upper_bound; i++){
            
            int target = c - (i*i);
            // cout<<i<<endl;
            if(binary_search(i,upper_bound,target))
                return true;
            // cout<<i<<endl;
        }
        
        return false;
    }
};