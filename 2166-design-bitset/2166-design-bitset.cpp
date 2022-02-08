class Bitset {
public:
    string s;
    int cnt;
    bool flipped;
    Bitset(int size) {
        
        for(int i=0; i<size; i++)
        {
            s+='0';
        }
        cnt = 0;
        flipped = false;
        
    }
    
    void fix(int idx) {
        
        if(flipped)
        { if(s[idx] == '1')
        {
            s[idx] = '0';
            cnt++;
        }
        }
        else
        {
            if(s[idx] == '0')
            {
                s[idx] = '1';
                cnt++;
            }
        }
        
      
        
        
    }
    
    void unfix(int idx) {
        
       if(flipped)
       {
           if(s[idx] == '0')
           {
               s[idx] = '1';
               cnt--;
           }
       }
        else
        {
            if(s[idx] == '1')
            {
                s[idx] = '0';
                cnt--;
            }
        }
        
        
    }
    
    void flip() {
        
        if(flipped)
        flipped = false;
        else
        flipped = true;
        cnt = s.size()-cnt;
    }
    
    bool all() {
        
        int n = s.size();
        
        if(cnt == n)
        return true;
        return false;
    }
    
    bool one() {
      
        if(cnt>0)
            return true;
        return false;
        
    }
    
    int count() {
        
        
        return cnt;
        
    }
    
    string toString() {
        if(flipped == false)
        return s;
        int n = s.size();
        string dup = s;
        for(int i=0; i<n; i++)
            if(s[i] == '0')
                dup[i] = '1';
            else
                dup[i] = '0';
        return dup;
        
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */