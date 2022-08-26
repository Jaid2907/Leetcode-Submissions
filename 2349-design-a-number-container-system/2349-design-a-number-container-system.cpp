class NumberContainers {
public:
    unordered_map<int,int> number_map;
    unordered_map<int,set<int> > index_map;
    
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(number_map.find(index) != number_map.end()){
            int num = number_map[index];
            index_map[num].erase(index);
            if(index_map[num].size() == 0)
                index_map.erase(num);
        }
        number_map[index] = number;
        index_map[number].insert(index);
        
       
    }
    
    int find(int number) {
     if(index_map.find(number) == index_map.end())
         return -1;
     return *index_map[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */