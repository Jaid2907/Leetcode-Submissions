class SeatManager {
public:
    set<int> s;
    int count = 1;
    SeatManager(int n) {
        
    }
    
    int reserve() {
        
        if(s.empty()){
            return count++;
        }
        else{
           int num = *s.begin();
            s.erase(num);
            return num;
        }
            
    }
    
    void unreserve(int seatNumber) {
        s.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */