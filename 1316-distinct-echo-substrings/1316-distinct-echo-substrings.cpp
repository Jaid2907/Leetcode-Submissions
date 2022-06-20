class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.size();
        vector<int> v(n,0);
        int ans = 0;
        int sum = 0;
        int k = 0;
        string str = "";
        unordered_map<string,int> mp;
        vector<string> temp;
        for(int i=0; i<n; i++){
           
            v.clear();
            sum = 0;
            k = 0;
            str = "";
            
            for(int j=i; j<n; j++){
                sum += text[j];
                v[k] = sum;
                str += text[j];
                
                if(mp.find(str) == mp.end() && v[k]%2 == 0 && v[k]/2 == v[(j-i)/2]){
                    temp.push_back(str);
                    mp[str]++;
                }
                
                k++;
                
            }
        }
        

        
        int flag = 0;
        for(int i=0; i<temp.size(); i++){
            
            flag = 0;
            string str = temp[i];
            
            if(str.size()%2 == 0){
                int j = 0, k = str.size()/2;
                
                while(k<str.size()){
                    if(temp[i][j] != temp[i][k]){
                        flag = 1;
                        break;
                    }
                    
                    j++;
                    k++;
                }
            }
            
            if(flag == 0 && str.size()%2 == 0){
             
             ans++;   
            }
                
        }
        
        return ans;
    }
};