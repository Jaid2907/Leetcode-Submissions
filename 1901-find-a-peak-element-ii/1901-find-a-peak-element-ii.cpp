class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector <int> ans;
        for(int i=0; i<m; i++)
        {
            int low = 0;
            int high = n-1;
            int mid;
            
            while(low<=high)
            {
                mid = (low+high)/2;
                
                if(( mid==0 || mat[i][mid]>mat[i][mid-1] )&&(mid == n-1 || mat[i][mid]>mat[i][mid+1]))
                {
                    
                    if((i==0 ||mat[i][mid]>mat[i-1][mid] )&&( i==m-1 || mat[i][mid]>mat[i+1][mid]))
                    {
                        
                        ans.push_back(i);
                        ans.push_back(mid);
                        return ans;
                    }
                    else
                       low = mid+1;
                } 
                else if (mid>0 && mat[i][mid]<mat[i][mid-1])
                {
                    high = mid-1;
                }
                else
                {
                    low = mid+1;
                }
            }
            
            low = 0;
            high = n-1;
    
            while(low<=high)
            {
                mid = (low+high)/2;
                
                if(( mid==0 || mat[i][mid]>mat[i][mid-1] )&&(mid == n-1 || mat[i][mid]>mat[i][mid+1]))
                {
                    
                    if((i==0 ||mat[i][mid]>mat[i-1][mid] )&&( i==m-1 || mat[i][mid]>mat[i+1][mid]))
                    {
                        
                        ans.push_back(i);
                        ans.push_back(mid);
                        return ans;
                    }
                    else
                        high = mid-1;
                } 
                else if (mid>0 && mat[i][mid]<mat[i][mid-1])
                {
                    low = mid+1;
                }
                else
                {
                   high = mid-1;
                }
            }
            
            
            
        }
    
        return ans;
    }
};