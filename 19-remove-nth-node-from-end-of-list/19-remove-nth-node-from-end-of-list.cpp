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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head, *q = head;
        
        int i = 0;
        
        while(i!=n){
            i++;
            p = p->next;
        }
        
        if(!p){
            return head->next;
        }
        
        while(p->next){
            p = p->next;
            q = q->next;
        }
        
        ListNode* temp = q->next;
        q->next = temp->next;
        delete temp;
        return head;
    }
};