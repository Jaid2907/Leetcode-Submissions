class Solution {
public:
    void addOne (string &s)
    {
        int n = s.size();
        int carry = 0;
        if(s[n-1] == '0')
        {
            s[n-1] = '1';
                return ;
        }
        else
        {
            s[n-1] = '0';
            carry = 1;
        }
        int j = n-2;
        while(carry && j>=0)
        {
            if(s[j] == '1')
            {
                s[j] = '0';
            }
            else
            {
                s[j] = '1';
                carry = 0;
            }
            j--;
            
        }
        
        if(carry)
            s.insert(0,"1");
        
    }
    int numSteps(string s) {
       
        int n = s.size();
        
        int cnt = 0;
        
        while(s.size() != 1)
        {
            if(s[s.size()-1] == '0')
            {
                s.pop_back();
            }
            else
            {
                addOne(s);
            }
            cnt++;
        }
        return cnt;        
        
    }
};