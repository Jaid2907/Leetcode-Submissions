/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        unordered_map <Node*, int> mp;
        unordered_map <int,Node*> mp2;
        Node* p = head;
       
        int i = 0;
        while(p)
        {
            mp[p] = i;
            i++;
            p = p->next;
            
        }
        
        vector<int> index(i);
        p = head;
        Node* new_head = new Node(p->val);
        Node* prev = new_head;
        i = 0;
        mp2[i] = new_head;
        if(p->random == NULL)
            index[i++] = -1;
        else
            index[i++] = mp[p->random];
        
        p=p->next;
        
        while(p)
        {
            Node* t = new Node(p->val);
            mp2[i] = t;
            if(p->random == NULL)
                index[i] = -1;
            else
                
                index[i] = mp[p->random];
            i++;
            prev->next = t;
            prev = t;
            p = p->next;
            
            
        }
        prev->next = NULL;
        
        p = new_head;
        i  = 0;
        while(p)
        {
            if(index[i] == -1)
                p->random = NULL;
            else
                p->random = mp2[index[i]];
            i++;
            p = p->next;
        }
        
        return new_head;
        
        
    }
};