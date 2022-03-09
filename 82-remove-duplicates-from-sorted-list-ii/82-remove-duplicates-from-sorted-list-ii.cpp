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
     
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* p = head;
        ListNode* last = dummy;
        
        while(p)
        {
            if( p->next && p->val == p->next->val)
            {   int val = p->val;
                while( p && p->val == val)
                {
                ListNode* t = p;
                last->next = p->next;
                 p = p->next;
                delete t;
                }
             
            }
            else
            {
                last = p;
                p = p->next;
            }
                
        }
        
        return dummy->next;
    }
};