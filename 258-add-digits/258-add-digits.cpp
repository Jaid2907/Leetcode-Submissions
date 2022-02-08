class Solution {
public:
    int addDigits(int num) {
        
        int n = num;
        int s = 0;
        int dup = n;
        while(1)
        {
            s=0;
            while(dup)
            {
                s += (dup%10);
                dup /= 10;
            }
            
            dup = s;
            
            if(dup/10 == 0)
                break;
            
        }
        
        return dup;
    }
};