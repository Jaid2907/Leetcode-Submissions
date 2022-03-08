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
    ListNode *detectCycle(ListNode *head) {
        
        unordered_map <ListNode*,int> mp;
        ListNode* fast = head;
        
        while(fast)
        {
            
            if(mp[fast] == 1)
                return fast;
            mp[fast] = 1;
            fast = fast->next;
            
        }
        
        return NULL;
        
        
    }
};