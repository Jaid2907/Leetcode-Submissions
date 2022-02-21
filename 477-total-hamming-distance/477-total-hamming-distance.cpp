class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
     int t = 32;
     int n = nums.size();
     vector<vector<int>> v;
        vector<int> temp;
        int ans = 0;
     for(int i=0; i<n; i++)
     {
         t = 32;
         int a = nums[i];
         while(t--)
         {
             if((a^1)%2 != 0)
                 temp.push_back(0);
             else
                 temp.push_back(1);
             
             a = a>>1;
         }
         
         v.push_back(temp);
         temp.clear();
     }
    
        
    int cnt0 = 0, cnt1 = 0;
    
    for(int i=0; i<32; i++)
    {
        for(int j=0; j<n; j++)
            if(v[j][i] == 1)
                cnt1++;
            else
                cnt0++;
       
        ans += cnt1*cnt0;
        cnt1 = 0;
        cnt0 = 0;
        
    }
        
     return ans;
      
    }
};