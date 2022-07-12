class StockSpanner {
public:
    stack <pair<int,int>> st;
    int i ;
    StockSpanner() {
        i = 0;
    }
    
    int next(int price) {
        
        if (i == 0){
            
            st.push({price,0});
            i++;
            return 1;
        }
        
        while(!st.empty() && st.top().first <= price)
            st.pop();
        
        int ans;
        
        if(!st.empty() && st.top().first > price){
            ans = i - st.top().second;
        }
        else if(st.empty()){
            ans = i + 1;
        }
        else
            ans = 1;
        st.push({price,i});
        i++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */