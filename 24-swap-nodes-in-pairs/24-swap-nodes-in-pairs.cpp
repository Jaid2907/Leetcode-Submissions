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
    ListNode* swapPairs(ListNode* head) {
        
        if(!head)
            return head;
        if(head->next == NULL)
            return head;
        int n = 0;
        ListNode* p = head;
        ListNode* prev =  NULL;
        ListNode* new_head;
        int flag = 0;
        
        while(p)
        {
            if(p && p->next)
            {
                ListNode* t = p->next->next;
                ListNode* s = p->next;
                p->next = t;
                s->next = p;
                if(prev)
                    prev->next = s;
                 prev = p;
                p=p->next;
                
                if(flag == 0)
                {
                    new_head = s;
                    flag = 1;
                }
               
                
            }
            else
            {
                p=p->next;
            }
            
            
        }
        
        return new_head;
        
        
        
    }
};