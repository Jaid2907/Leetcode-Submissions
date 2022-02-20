class Solution {
public:
    void reverse(vector<char>& s, int n, int i)
    {
        if(i>=n/2)
            return;
        
        swap(s[i],s[n-i-1]);
        reverse(s,n,i+1);
        
    }
    void reverseString(vector<char>& s) {
       
        reverse(s,s.size(),0);
        
    }
};