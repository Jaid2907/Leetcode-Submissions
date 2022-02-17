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
    ListNode* deleteMiddle(ListNode* head) {
        int i = 0;
        ListNode* p = head;
        ListNode* prev = NULL;
        if(p->next == NULL)
        {
            delete head;
            return NULL;
        }
        int n = 0;
        while(p)
        {
            p = p->next;
            n++;
        }
        p = head;
        while(p)
        {
            prev = p;
            p = p->next;
            i++;
            
            if( i == n/2)
            {
                ListNode* t = p;
                prev->next = p->next;
                delete t;
                break;
            }
               
        }
        
        return head;
    }
};