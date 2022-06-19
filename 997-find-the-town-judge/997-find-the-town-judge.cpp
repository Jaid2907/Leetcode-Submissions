class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
         vector<vector<int>> adj(n, vector<int>(n,0));
        
        for(auto it: trust){
            adj[it[0]-1][it[1]-1] = 1;
        }
        int flag = 0;
        int i, j;
        for(i=0; i<n; i++){
            flag = 0;
            
            for(j=0; j<n; j++){
                
                if(adj[i][j] == 1){
                    flag = 1;
                    break;
                }
            }
            
            if(flag == 0){
                
                for(int k=0; k<n; k++){
                    if(adj[k][i] == 0 && k != i){
                        flag = 1;
                        break;
                    }
                }
            }
            
            if(flag == 0)
                return i+1;
        }
        
        return -1;
    }
};