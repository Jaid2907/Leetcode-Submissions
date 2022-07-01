class MyCircularQueue {
public:
    vector<int> queue;
    int front, rear;
    int k;
    
    MyCircularQueue(int k) {
        queue.resize(k,0);
        front = -1;
        rear = -1;
        this->k = k;
    }
    
    bool enQueue(int value) {
        
        if(!isFull()){
            
            rear = (rear+1)%k;
            queue[rear] = value;
            if(front == -1)
                front = rear;
            
            return true;
        }
        else
            return false;
        
        
    }
    
    bool deQueue() {
        
        if(!isEmpty()){
            if(front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            front = (front+1)%k;
            
            return true;
        }
        
        return false;
    }
    
    int Front() {
        if(!isEmpty())
        return queue[front];
        
        return -1;
    }
    
    int Rear() {
        if(!isEmpty())
        return queue[rear];
        return -1;
    }
    
    bool isEmpty() {
     
        return rear == -1 && front == -1;
    }
    
    bool isFull() {
        
        return (rear+1)%k == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */