/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length (ListNode* head){
        int cnt = 0;
        
        while(head){
            head = head->next;
            cnt++;
        }
        
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int len1 = length(headA);
        int len2 = length(headB);
        int k;
        ListNode* p = headA, *q = headB;
        
        
        if(len2>len1){
             k = len2-len1;
            while(k--){
                q = q->next;
            }
            
        }
        else
        {
            k = len1-len2;
            while(k--){
                p = p->next;
            }
        }
        
        while(p && q){
            if(p == q)
                return p;
            p = p->next;
            q = q->next;
            
        }
            
            
       
        
        
        return NULL;
    }
};