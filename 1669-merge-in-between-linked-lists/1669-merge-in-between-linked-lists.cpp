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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* new_head = new ListNode(-1);
        ListNode* p = list1;
        new_head->next = p;
        
        ListNode* list2_start = list2;
        ListNode* list2_end;
        
        while(list2_start->next)
            list2_start = list2_start->next;
        list2_end = list2_start;
        list2_start = list2;
        int i = 0;
        while(i!=a-1)
        {
            p = p->next;
            i++;
        }
        
        ListNode* temp = p;
        while(i!=b+1)
        {
            temp =temp->next;
            i++;
        }
        p->next = list2_start;
        list2_end->next = temp;
        return new_head->next;
        
    }
};