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
    void split(ListNode* head, ListNode** a, ListNode** b)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast)
        {
            fast = fast->next;
            if(fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        
        *a = head;
        *b = slow->next;
        slow->next = NULL;
        
        
    }
    ListNode* merge (ListNode* list1, ListNode* list2)
    {
        if(!list1 && !list2)
            return NULL;
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
    void mergeSort(ListNode** head)
    {
        ListNode* h2 = *head;
        if(h2 == NULL || h2->next == NULL)
            return;
        ListNode* a, *b;
        split(h2,&a,&b);
        mergeSort(&a);
        mergeSort(&b);
        *head = merge(a,b);
        
    }
    ListNode* sortList(ListNode* head) {
        mergeSort(&head);   
        return head;
    }
};