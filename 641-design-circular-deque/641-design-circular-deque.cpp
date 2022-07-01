class MyCircularDeque {
public:
    list<int> queue;
    int  k;
    
    
    
    MyCircularDeque(int k) {
        
        this->k = k;
        
    }
    
    bool insertFront(int value) {
        
        if(!isFull()){
            queue.push_front(value);
            return true;
        }
        return false;
        
    }
    
    bool insertLast(int value) {
        
        if(!isFull()){
            queue.push_back(value);
            
            return true;
        }
        
        return false;
        
    }
    
    bool deleteFront() {
        
        if(!isEmpty()){
            queue.pop_front();
        
            return true;
        }
        
        return false;
    }
    
    bool deleteLast() {
        if(!isEmpty()){
            queue.pop_back();
            
            return true;
        }
        
        return false;
        
    }
    
    int getFront() {
        
        if(!isEmpty()){
            return queue.front();
        }
        return -1;
    }
    
    int getRear() {
        
        if(!isEmpty()){
            return queue.back();
        }
        return -1;
        
    }
    
    bool isEmpty() {
     return queue.size() == 0;   
    }
    
    bool isFull() {
        return queue.size() == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */