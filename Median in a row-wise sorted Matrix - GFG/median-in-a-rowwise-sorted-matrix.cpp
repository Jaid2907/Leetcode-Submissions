//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
int check(int mid, vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    int cnt = 0;

    for(int i = 0; i<m; i++){
        auto it = upper_bound(grid[i].begin(), grid[i].end(),mid);
        if(it == grid[i].begin())
            continue;
        it--;
        cnt += (it-grid[i].begin()+1);
    }

    return cnt;
}
class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here      
        int low = 1 , high = 1e5;
        int m = matrix.size();
        int n = matrix[0].size();
        int k = m*n/2+1;
        int ans = -1;
    
        while(low <= high){
            int mid = low + (high-low)/2;
            int cnt = check(mid,matrix);
    
            if(cnt >= k){
                ans = mid;
            }
    
            if(cnt >= k ){
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
    
        return ans;

    }
    
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends