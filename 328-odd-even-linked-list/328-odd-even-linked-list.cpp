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
    ListNode* oddEvenList(ListNode* head) {
        
        ListNode* odd = new ListNode(-1), *even = new ListNode(-1);
        ListNode* first_head = odd, *second_head = even;
        int f = 0;
        ListNode* curr = head;
        
        while(curr){
            if(f == 0){
                f = 1;
                odd->next = curr;
                odd = curr;
                curr = curr->next;
            }
            else{
                f = 0;
                even->next = curr;
                even = curr;
                curr = curr->next;
            }
        }
        
        odd->next = second_head->next;
        even->next = NULL;
        
        return first_head->next;
        
    }
};