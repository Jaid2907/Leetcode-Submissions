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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
     
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        ListNode* p = new ListNode(101);
        ListNode* prev = p;
        while(list1 && list2)
        {
            if(list1->val<list2->val)
            {
                ListNode* p = list1;
                list1 = list1->next;
                prev->next = p;
                p->next = NULL;
                prev = p;
            }
            else
            {
                ListNode* p = list2;
                list2 = list2->next;
                prev->next = p;
                p->next = NULL;
                prev = p;
            }
            
        }
        if(list1)
            prev->next = list1;
        if(list2)
            prev->next = list2;
        return p->next;
    }
};