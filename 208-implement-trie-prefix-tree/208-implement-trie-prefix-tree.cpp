class Node{
    public:
    vector<Node*> v;
    bool flag = false;
    
    Node(){
        v.resize(26);
    }

};

class Trie {
public:
    Node* root;
    
    Trie() {
     root = new Node();   
    }
    
    void insert(string word) {
        Node *p = root;
        for(int i=0; i<word.size(); i++){
            if(p->v[word[i]-'a'] == NULL){
                p->v[word[i]-'a'] = new Node();
                p = p->v[word[i]-'a'];
            }
            else
                p = p->v[word[i]-'a'];
        }
        p->flag = true;
    }
    
    bool search(string word) {
        Node* p = root;
        for(int i=0; i<word.size(); i++){
            if(p->v[word[i]-'a'] != NULL){
                p = p->v[word[i]-'a'];
            }
            else
                return false;
        }
        if(p->flag)
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* p = root;
        
        for(int i=0; i<prefix.size(); i++){
            if(p->v[prefix[i]-'a'] != NULL){
                p = p->v[prefix[i]-'a'];
            }
            else
                return false;
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