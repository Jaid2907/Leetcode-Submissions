class Solution {
public:
    string convert(string s, int numRows) {
        
        int row = 0;
        int k =0; 
        int n = s.size();
        if(numRows == 1)
            return s;
        vector<vector<char>> v(numRows,vector<char>(n,'0'));
        string ans;
        int i = 0, j = 0;
        int step = 1;
        
        while(k<n)
        {
            v[i][j] = s[k++];
            i = i + step;
            if(step == -1)
                j++;
            if(i == numRows)
            {
                i-=2;
                
                step = -1;
                j++;
            }
            if(i == -1)
            {
                step = 1;
                i = 1;
                
            }
        }
        
        for(int i=0; i<v.size(); i++)
        {
            for(int j=0; j<v[0].size(); j++)
            {if(v[i][j] == '0')
                    continue;
                    ans += v[i][j];
            }
        }
        
        return ans;
    }
};