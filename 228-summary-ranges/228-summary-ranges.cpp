class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
         vector<string> ans;
         int n = nums.size();
        if(n == 0)
            return ans;
        int start = nums[0], end;
       
        string temp = "";
        long long int t;
        int startindex = 0;
        for(int i=1; i<n; i++)
        {
            t = nums[i]*1ll-nums[i-1];
            if( t == 1)
                continue;
            temp = "";
            if(i-1-startindex)
            {   temp += to_string(start);
                temp += "->";
                temp += to_string(nums[i-1]);
            }
            else
                
            temp += to_string(start);
            ans.push_back(temp);
            start = nums[i];
            startindex = i;
            
        }
        
        temp = "";
          if(n-1-startindex)
          {
              temp += to_string(start);
              temp += "->";
              temp += to_string(nums[n-1]);
          }
            
        else
            temp += to_string(start);
        
          ans.push_back(temp);
        
       
        return ans;
    }
};