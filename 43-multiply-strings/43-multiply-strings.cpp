class Solution {
public:
    string addStrings(string& a, string& b)
    {
        int n1 = a.size()-1;
        int n2 = b.size()-1;
        int temp;
        char temp2;
        if(a == "")
            return b;
        
        string ans;
        int carry = 0;
        while(n1>=0 && n2>=0)
        {
            temp = (a[n1]-48) + (b[n2]-48) + carry;
            
            carry = temp/10;
            temp2 = char(temp%10+48); 
            ans.push_back(temp2);
            n1--;
            n2--;
        }
        while(n1>=0)
        {
             temp = carry+a[n1]-48;
            carry = temp/10;
             temp2 = char(temp%10+48);
            ans.push_back(temp2);
            n1--;
        }
        while(n2>=0)
        {
             temp = carry + b[n2]-48;
            carry = temp/10;
             temp2 = char(temp%10+48);
            ans.push_back(temp2);
            n2--;
        }
        
        if(carry)
            ans.push_back(char(carry+48));
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
    
    string multiply(string num1, string num2) {
        
        if(num1 == "0" || num2 == "0")
            return "0";
        
        string t, ans = "";
        int temp, carry = 0, k = 0;
        
       
            int n1 = num1.size()-1;
            int n2 = num2.size()-1;
            
            for(int i=n1; i>=0; i--)
            {
                int mul = num1[i]-48;
                int j = n2;
                t = "";
                carry = 0;
                
                while(j>=0)
                {
                    temp = ((num2[j]-48) * mul);
                    
                    temp += carry;
                    
                    carry = temp/10;
                    t.push_back(char((temp%10) + 48));
                    j--;
                
                }
                
                int var = k;
                
                if(carry)
                    t.push_back(char(carry+48));
                
                reverse(t.begin(),t.end());
                
                while(var--)
                {
                    t.push_back('0');
                }
                
                k++;
                ans = addStrings(ans,t);
                
                t = "";
                
                
                
            
        }
            
          
        return ans;
        
    }
};