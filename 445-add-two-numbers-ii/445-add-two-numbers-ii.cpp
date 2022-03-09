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
    ListNode* reverse (ListNode* head)
    {
        ListNode* p = head;
        ListNode* q =NULL, *r = NULL;
        
        while(p)
        {
            q = p;
            p = p->next;
            q->next = r;
            r = q;
        }
        
        return r;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* h1 = reverse(l1);
        ListNode* h2 = reverse(l2);
        ListNode* p = h1, *q = h2;
        ListNode* prev_p, *prev_q;
        int carry = 0;
        ListNode* last;
        while(p && q)
        {
            int s = p->val + q->val + carry;
            p->val = s%10;
            carry = s/10;
          
            prev_p = p;
            prev_q = q;
            last = p;
            p = p->next;
            q = q->next;
            
        }
        
        while(p)
        {
            int s = p->val + carry;
            p->val = s%10;
            carry = s/10;
            prev_q->next = p;
            prev_q = p;
            last = p;
            p = p->next;
        }
        while(q)
        {
            int s = q->val + carry;
            q->val = s%10;
            carry = s/10;
            prev_p->next = q;
            prev_p = q;
            last = q;
            q = q->next;
        }
        
        if(carry>0)
        {
            ListNode* t = new ListNode();
            t->val = carry;
            last->next = t;
            t->next = NULL;
        }
            
        h1 = reverse(h1);
        
        return h1;
        
    }
};