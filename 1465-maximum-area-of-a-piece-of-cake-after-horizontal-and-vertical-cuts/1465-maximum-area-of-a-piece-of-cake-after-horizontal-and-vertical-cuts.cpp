class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        horizontalCuts.push_back(0);
        verticalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
        int nhw = horizontalCuts.size();
        int nvw = verticalCuts.size();
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int mod = 1e9+7;
        
        int max_hor = INT_MIN;
        int max_ver = INT_MIN;
        
        for(int i=1; i<nhw; i++){
            max_hor = max (max_hor, horizontalCuts[i]-horizontalCuts[i-1]);
        }
        
        for(int i=1; i<nvw; i++){
            max_ver = max(max_ver, verticalCuts[i]-verticalCuts[i-1]);
        }
        
        return (max_hor%mod * 1ll* max_ver%mod)%mod;
    }
};