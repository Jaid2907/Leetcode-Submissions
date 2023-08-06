//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int check(vector<vector<int>>& mat, int r, int c, int mid){
        int cnt = 0;
        
        for(int i = 0; i<r; i++){
            auto it = upper_bound(mat[i].begin(), mat[i].end(), mid);
            if(it != mat[i].begin()){
                it--;
                cnt += (it-mat[i].begin())+1;
                
            }
            
        }
        
        return cnt;
    }
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here      
        int low = 1, high = 2000;
        int desired = (r*c+1)/2;
        int ans = -1;
        
        while(low <= high){
            
            int mid = low + (high-low)/2;
            int cnt = check(matrix,r,c,mid);
            
            if(cnt >= desired){
                ans = mid;
                high = mid - 1;
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