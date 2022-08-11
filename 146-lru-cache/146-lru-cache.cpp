

class LRUCache {

public:
    class node{
  public:
    int key, val;
    node* next;
    node* prev;
    
    node(int key, int val){
        this->key = key;
        this->val = val;
    }
};
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int size;
    unordered_map<int,node*> mp;
    
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
            node* temp = mp[key];
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            node* head_next = head->next;
            head->next = temp;
            temp->prev = head;
            temp->next = head_next;
            head_next->prev = temp;
        return mp[key]->val;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            
            node* temp = mp[key];
            temp->val = value;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            node* head_next = head->next;
            head->next = temp;
            temp->prev = head;
            temp->next = head_next;
            head_next->prev = temp;
            
        }
        else{
            if(mp.size() == size){
                node* temp = tail->prev;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                mp.erase(temp->key);
                delete temp;
            }
            
            node* head_next = head->next;
            head->next = new node(key,value);
            mp[key] = head->next;
            head->next->prev = head;
            head->next->next = head_next;
            head_next->prev = head->next;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */