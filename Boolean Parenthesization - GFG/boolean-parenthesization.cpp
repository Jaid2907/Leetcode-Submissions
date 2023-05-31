//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countWays(int n, string s){
        // code here
        vector<char> operators;
        vector<char> operands;
        
        for(int i = 0; i<n; i++){
            if(s[i] == 'T'|| s[i] == 'F')
                operands.push_back(s[i]);
            else
                operators.push_back(s[i]);
        }
        
        n = operands.size();
        
        vector<vector<int>> dpt(n, vector<int>(n,0));
        vector<vector<int>> dpf(n, vector<int>(n,0));
        
        for(int i = n-1; i>=0; i--){
            
            for(int j = i; j<n; j++){
                
                if(j == i){
                    dpt[i][j] = operands[i] == 'T' ? 1 : 0;
                    dpf[i][j] = operands[i] == 'T' ? 0 : 1;
                    continue;
                }
                
                for(int k = i; k<j; k++){
                    
                        int leftT, leftF, rightT, rightF;
                        leftT = dpt[i][k];
                        leftF = dpf[i][k];
                        rightT = dpt[k+1][j];
                        rightF = dpf[k+1][j];
                        
                    if(operators[k] == '|'){
                        (dpt[i][j] += leftT*rightT + leftT*rightF + leftF*rightT)%=1003;
                        (dpf[i][j] += leftF*rightF)%=1003;
                    }
                    else if(operators[k] == '^'){
                        (dpt[i][j] += leftT*rightF + leftF*rightT)%=1003;
                        (dpf[i][j] += leftT*rightT + leftF*rightF)%=1003;
                    }
                    else{
                        
                        (dpt[i][j] += leftT*rightT)%=1003;
                        (dpf[i][j] += leftT*rightF + leftF*rightF + leftF*rightT)%=1003;
                        
                    }
                }
            }
        }
        
        
        
        return dpt[0][n-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends