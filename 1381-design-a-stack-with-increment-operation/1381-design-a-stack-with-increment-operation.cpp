class CustomStack {
public:
    vector<int> st;
    int top;
    int size;
    CustomStack(int maxSize) {
        st.resize(maxSize,-1);
        top = -1;
        size = maxSize;
    }
    
    void push(int x) {
        
        if(top+1 != size){
            top++;
            st[top] = x;
        }
            
    }
    
    int pop() {
        
        if(top == -1)
            return -1;
        int a = st[top];
        top--;
        return a;
    }
    
    void increment(int k, int val) {
        
        int boundary = k;
        if(top+1<k)
            boundary = top+1;
        
        for(int i=0; i<boundary; i++)
            st[i] += val;
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */