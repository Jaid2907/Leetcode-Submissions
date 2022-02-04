class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
vector<int> ans;
int first_row = 0;
int first_col = 0;
int last_row = matrix.size() - 1;
int last_col = matrix[0].size()-1;
int i = 0, j = 0;
int flag = 0;
int flag2 = 0;
vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), 0));
while (1)
{flag2 = 0;
    while (j <= last_col)
    {
        if (!visited[i][j])
        {
            ans.push_back(matrix[i][j]);
            visited[i][j] = 1;
            j++;
        } 
        else
        {
            
            flag = 1;
            break;
        }
        
        flag2 = 1;
        
    }
    
    if (flag)
        break;
    first_row++;
    j--;
    i++;

    while (i <= last_row)
    {
        if (!visited[i][j])
        {ans.push_back(matrix[i][j]);
            visited[i][j] = 1;
         i++;
        } 
        else
        {
            flag = 1;
            break;
        }
        
        flag2 = 1;
        
    }
    last_col--;
    i--;
    j--;
    if (flag)
        break;
    while (j >= first_col)
    {
        if (!visited[i][j])
        {ans.push_back(matrix[i][j]);
         visited[i][j] = 1;
         j--;
            
        } 
        else
        {
            flag = 1;
            break;
        }
     flag2 = 1;   
    }

    last_row--;
    j++;
    i--;
    if (flag)
        break;

    while (i >= first_row)
    {
        if (!visited[i][j])
        {
            visited[i][j] = 1;
            ans.push_back(matrix[i][j]);
             i--;
        } 
        else
        {
            flag = 1;
            break;
        }
       flag2 = 1;
    }
    first_col++;
    i = first_row;
    j = first_col;

    if (flag)
        break;
    
   
    
    if(flag2 == 0)
        break;
}
return ans;
        
    }
};