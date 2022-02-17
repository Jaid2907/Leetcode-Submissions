/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        ListNode* p = head;
        if(p->next == NULL)
            return ;
        while(p)
        {
            v.push_back(p);
            p = p->next;
        }
        
        int i = 0;
        int n = v.size();
        p = head;
        if(n%2 == 0)
        {while(i<n/2)
        {
            v[i]->next = v[n-i-1];
            if(i+1 == n-i-1)
                v[n-i-1]->next = NULL;
            else
            v[n-i-1]->next = v[i+1];
            i++;
            
        }
        }
        else
        {
            while(i<n/2)
            {
                v[i]->next = v[n-i-1];
                
                 v[n-i-1]->next = v[i+1];
                 i++;
            }
            
            v[n/2+1]->next = v[n/2];
            v[n/2]->next = NULL;
            
            
        }
        
        
    }
};