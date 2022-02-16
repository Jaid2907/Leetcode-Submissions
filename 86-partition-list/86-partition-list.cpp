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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode();
        
        ListNode* greater = new ListNode();
        ListNode* q = less;
        ListNode* r = greater;
        ListNode* p = head;
        
        while(p)
        {
            if(p->val<x)
            {
                ListNode* t = p;
                p = p->next;
                q->next = t;
                t->next = NULL;
                q = q->next;
                
            }
            else
            {
                ListNode* t = p;
                 p = p->next;
                r->next = t;
                t->next = NULL;
                r = r->next;
            }
        }
        ListNode* t = greater;
        q->next = greater->next;
        delete t;
        return less->next;
    }
};