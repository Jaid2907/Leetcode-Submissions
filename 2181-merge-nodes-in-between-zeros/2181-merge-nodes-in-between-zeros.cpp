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
    ListNode* mergeNodes(ListNode* head) {
       
        ListNode* p = head->next;
        ListNode* q = head;
        ListNode* prev;
        int sum = 0;
        while(p)
        {
            
            if(p->val == 0)
            {
                
                q->val = sum;
                prev = q;
                q=q->next;
                sum = 0;
            }
            else
            {
                sum += p->val;
            }
            
            p = p->next;
        }
        
        p = q;
        
        while(p)
        {
            ListNode* t = p;
            prev->next = p->next;
            delete t;
            p = prev->next;
            
        }
        
        
        return head;
        
        
        
    }
};