//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int n, int m, int x, int y){    
        // code here
        vector<vector<int>> vis(n, vector<int>(m,0));
        x--; y--;
        vis[x][y] = 1;
        queue<pair<int,int>> q;
        q.push({x,y});
        int cnt = 0;
        vector<int> row = {0,0,1,-1};
        vector<int> col = {1,-1,0,0};
        
        while(!q.empty()){
            int size = q.size();
            cnt++;
            while(size--){
                auto it = q.front();
                int x = it.first;
                int y = it.second;
                q.pop();
                
                for(int k = 0; k<4; k++){
                    
                    int i = x + row[k];
                    int j = y + col[k];
                    
                    if(i>=0 && j>=0 && i<n && j<m && !vis[i][j]){
                        vis[i][j] = 1;
                        q.push({i,j});
                    }
                }
            }
        }
        
        return cnt-1;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends