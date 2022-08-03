class MyCalendar {
public:
    vector<pair<int,int>> v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        int flag = 0;
        
        for(auto &it: v){
            if(start>=it.second || end<=it.first){
               continue;
            }
            else{
                flag = 1;
                break;
            }
        }
        
        if(!flag){
            v.push_back({start, end});
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */