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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(k == 0 || head==NULL)
            return head;
        int n = 0;
        ListNode* p = head, *q = head;
        ListNode* prev;
        
        while(p)
        {
            prev = p;
            p = p->next;
            n++;
        }
        
        k = k%n;
        
        int i = 0;
        ListNode* prev2;
        p = head;
        
        if(k!=0)
        {
             while(i!=n-k)
        {
            prev2 = p;
            p = p->next;
            i++;
           
        }
       
        prev2->next = NULL;
        prev->next = head;
        
        
        }
        
        
        return p;
    }
};