class Solution {
public:
    static bool compare (vector<int>& a, vector<int>& b){
        
        
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int ans = 0;
        int i  = 0;
        int n = boxTypes.size();
        
        while( i< n && truckSize){
        
            if(boxTypes[i][0] <= truckSize){
                ans += boxTypes[i][0]*boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else{
                ans += truckSize * boxTypes[i][1];
                break;
            }
            
            i++;
               
        }
        
        return ans;
    }
};