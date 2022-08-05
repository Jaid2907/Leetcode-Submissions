class Node{
    public:
    vector<Node*> vec;
    bool flag = false;
     Node(){
         vec.resize(26);
     }
    
};
class Trie {
public:
    Node* root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        int n = word.size();
        Node* node = root;
        
        for(int i = 0; i<n; i++){
            
            if(node->vec[word[i]-97] == NULL){
                Node* temp = new Node();
                node->vec[word[i]-97] = temp;
                node = temp;
            }
            else{
                node = node->vec[word[i]-97];
            }
           
        }
        
        node->flag = true;
        
    }
    
    bool search(string word) {
        
        Node* node = root;
        int n = word.size();
        
        for(int i = 0; i<n; i++){
            
            if(node->vec[word[i]-97] == NULL){
                return false;
            }
            node = node->vec[word[i]-97];
        }
        
        return node->flag == true;
        
    }
    
    bool startsWith(string prefix) {
        
        Node* node = root;
        int n =  prefix.size();
        
        for(int i = 0; i<n; i++){
            if(node->vec[prefix[i]-97] == NULL){
                return false;
            }
            node = node->vec[prefix[i]-97];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */