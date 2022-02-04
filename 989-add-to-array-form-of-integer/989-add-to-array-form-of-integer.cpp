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
        if(b == "")
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
    vector<int> addToArrayForm(vector<int>& num, int k) {
        string a = "";
        
        for(auto& it: num)
            a.push_back(char(it+48));
        string b = to_string(k);
        
        string c = addStrings(a,b);
        
        vector<int> ans;
        for(int i=0; i<c.size(); i++)
            ans.push_back(c[i]-48);
        
        return ans;
        
    }
};