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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     unordered_map <ListNode* , int> mp;
        ListNode* p = headA;
        
        while(p){
            mp[p]++;
            p = p->next;
        }
        
        p = headB;
        
        while(p){
            if(mp.find(p) != mp.end())
                return p;
            
            p = p->next;
        }
        
        return NULL;
    }
};