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
    int pairSum(ListNode* head) {
        
        ListNode* slow= head, *fast = head;
        ListNode* prev;
        while(fast)
        {
            fast = fast->next;
            
            if(fast)
            {
                prev = slow;
                slow = slow->next;
                fast = fast->next;
            }
        }
        
        ListNode* p = prev->next;
        prev->next = NULL;
        ListNode* q = NULL, *r = NULL;
        
        while(p)
        {
            q = p;
            p = p->next;
            q->next = r;
            r = q;
        }
        
        prev->next = r;
        
        p = head;
        q = prev->next;
        int maxi = INT_MIN;
        
        while(q)
        {
            maxi = max(maxi,p->val+q->val);
            p = p->next;
            q = q->next;
            
        }
        
        return maxi;
        
    }
};