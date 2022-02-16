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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pr = new ListNode();
        pr->val = 1000;
        pr->next = head;
        ListNode* p = pr;
        ListNode* prev = pr;
        
        while(p)
        {
            if(p && p->next && p->val == p->next->val)
            {
                ListNode* q = p;
                int a = p->val;
                while(q && q->val == a)
                {
                    ListNode* temp = q;
                    prev->next = q->next;
                    delete temp;
                    q = prev->next;   
                }
                p = q;
            }
            else
            {
                prev = p;
                p=p->next;
            }
            
        }
        
        return pr->next;
    }
};