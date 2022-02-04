class Solution {
public:
    string addString(string& a, string& b)
    {
        int n1 = a.size()-1;
        int n2 = b.size()-1;
        int temp;
        char temp2;
        if(a == "0")
            return b;
        if(b == "0")
            return a;
        
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
    
    string addStrings(string num1, string num2) {
        
        return addString(num1,num2);
    }
};