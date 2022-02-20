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
    ListNode* swap(ListNode* head)
    {
        if(head && head->next)
        {
            ListNode* p = head->next->next;
            ListNode* q = head->next;
            
            head->next = swap(head->next->next);
            q->next = head;
            return q;
        }
        
        return head;
    }
    ListNode* swapPairs(ListNode* head) {
        
        return swap(head);
    }
};