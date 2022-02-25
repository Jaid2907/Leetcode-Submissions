class Solution {
public:
    int compareVersion(string version1, string version2) {
     
        int i = 0;
        int n1 = version1.size();
        int n2 = version2.size();
        vector<int> v1,v2;
        version1 += '.';
        version2 += '.';
        while(i<n1)
        {
            string temp = "";
            while(version1[i] != '.')
            {
             
                temp += version1[i];
                i++;
            }  
            
            
            v1.push_back(stoi(temp));
            i++;
            
        }
        
        i = 0;
        while(i<n2)
        {
             string temp = "";
            while(version2[i] != '.')
            {
             
                temp += version2[i];
                i++;
            }  
            
            
            v2.push_back(stoi(temp));
            i++;
        }
        
       while(v1.size()<v2.size())
           v1.push_back(0);
        while(v2.size()<v1.size())
            v2.push_back(0);
        
        for(int i=0; i<v1.size(); i++)
        {
            if(v1[i]>v2[i])
                return 1;
            else if(v1[i]<v2[i])
                return -1;
        }
        
        return 0;
        
        return 0;
    }
};