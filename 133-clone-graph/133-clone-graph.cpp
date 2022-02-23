/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
   5/.,
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(!node)
            return node;
        queue<Node*> q;
        q.push(node);
        Node* first;
        int flag = 0;
        vector<Node*> v(102);
        unordered_map <Node*,bool> visited;
        visited[node] = true;
        while(!q.empty())
        {
            int size = q.size();
            
            while(size--)
            {
                Node* p = q.front();
                q.pop();
                Node* t = new Node();
                t->val = p->val;
                v[t->val] = t;
                visited[p] = true;
                if(flag == 0)
                {
                    first = t;
                    flag = 1;
                }
                int i = 0;
                while(i<p->neighbors.size())
                {
                    if(visited[p->neighbors[i]] != true)
                        q.push(p->neighbors[i]);
                    i++;
                }
                    
            }
        }
        
        
        visited.clear();
        queue<Node*> q2;
        q.push(node);
        q2.push(first);
        // visited[node] = true;
        while(!q.empty())
        {
            int size = q.size();
            
            while(size--)
            {
                Node* p = q.front();
                Node* t = q2.front(); 
                q.pop();
                q2.pop();
                int i = 0;
                visited[p] = true;
                
                if(t->neighbors.size() == 0)
                while(i<p->neighbors.size())
                {
                    t->neighbors.push_back(v[p->neighbors[i]->val]);
                    i++;
                }
                
                i = 0;
                while(i<p->neighbors.size())
                {
                    if(visited[p->neighbors[i]] != true)
                    {
                        q.push(p->neighbors[i]);
                        q2.push(t->neighbors[i]);
                    }
                    i++;
                }
                
            }
        }
        
        return first;
        
    }
};