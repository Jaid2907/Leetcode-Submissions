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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* p = l1, *q = l2;
        int carry = 0;
        int sum = 0;
        ListNode* prev;
        
        while(p && q)
        {
            sum = p->val + q->val + carry;
            p->val = sum%10;
            carry = sum/10;
            
            prev = p;
            p = p->next;
            q = q->next;
            
        }
        
        if(p)
        {
            while(p)
            {
                sum = p->val + carry;
                p->val = sum%10;
                carry = sum/10;
                prev = p;
                p = p->next;
            }
        }
        
        else
        {
            prev->next = q;
            while(q)
            {
                sum = q->val + carry;
                q->val = sum%10;
                carry = sum/10;
                prev= q;
                q = q->next;
            }
        }
        
        if(carry)
        {
            ListNode* t = new ListNode();
            t->val = carry;
            prev->next = t;
            t->next = NULL;
        }
        return l1;
    }
};