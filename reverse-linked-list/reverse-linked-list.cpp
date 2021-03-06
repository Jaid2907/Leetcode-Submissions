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
    ListNode* reverse(ListNode* curr, ListNode* prev)
    {
        if(curr == NULL)
            return prev;
        ListNode* p = curr->next;
        curr->next = prev;
        prev = curr;
        
        return reverse(p,prev);
        
    }
    ListNode* reverseList(ListNode* head) {
        
        return reverse(head,NULL);
        
    }
};