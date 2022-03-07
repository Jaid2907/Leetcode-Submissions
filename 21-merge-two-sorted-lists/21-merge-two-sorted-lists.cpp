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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
     
       
        ListNode* p = list1, *q = list2;
        ListNode* dummy = new ListNode();
        ListNode* last = dummy;
        int flag = 0;
        while(p && q)
            
        {
            if(p->val<q->val)
            {
                
                ListNode* t = p;
                p = p->next;
                t->next = q;
                last->next = t;
                last = t;
                
            }
            else
            {
                
                ListNode* t = q;
                q = q->next;
                t->next = p;
                last->next = t;
                last = t;
            }
        }
        
        while(p)
        {
                ListNode* t = p;
                p = p->next;
                t->next = q;
                last->next = t;
                last = t;   
        }
        
        while(q)
        {
                ListNode* t = q;
                q = q->next;
                t->next = p;
                last->next = t;
                last = t;
        }
        
        return dummy->next;
    }
};