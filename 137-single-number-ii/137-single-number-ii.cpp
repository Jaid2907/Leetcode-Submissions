class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //Bit Manipulation
        
         long long res = 0;
        int n = nums.size();
        
        for(int i=0; i<32; i++)
        {
            int p =0;
            
            for(int j=0; j<n; j++)
            {
                p+= (abs(nums[j]) & (1<<i))!=0? 1:0;
            }
            
            p %= 3;
            res += pow(2,i)*p;
            
            
        }
        
        int cnt = 0;
        cout<<res<<endl;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == res)
                cnt++;
        }
        
        return cnt == 1? res:-res;
        
    }
};