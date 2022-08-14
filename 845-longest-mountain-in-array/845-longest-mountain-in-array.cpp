class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int cnt = 0;
        int ans = 0;
        int n = arr.size();
        vector<int> forward(n,1), backward(n,1);
        
        for(int i = 1; i<n; i++){
            if(arr[i] > arr[i-1]){
                forward[i] = forward[i-1]+1;
            }
        }
        for(int j = n-2; j>=0; j--){
            if(arr[j] > arr[j+1]){
                backward[j] = backward[j+1] + 1;
            }
        }
        
        for(int i = 0; i<n; i++){
            if(forward[i] != 1 && backward[i] != 1)
            ans = max(ans, forward[i] + backward[i] - 1);
        }
        
        // for(int i = 0; i<n; i++)
        //     cout<<forward[i]<<" ";
        // cout<<endl;
        // for(int j = 0; j<n; j++)
        //     cout<<backward[j]<<" ";
        // cout<<endl;
        return ans;
    }
};