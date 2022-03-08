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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast)
        {
            fast = fast->next;
            
             if(slow == fast)
                return true;
            if(fast)
            {
                fast = fast->next;
                slow = slow->next;
            }
            
           
        }
        
        
        return false;
    }
};