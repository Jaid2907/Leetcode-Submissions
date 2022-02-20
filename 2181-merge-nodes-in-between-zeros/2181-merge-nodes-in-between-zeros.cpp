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
    ListNode* mergeNodes(ListNode* head) {
        vector<int> v;
        ListNode* p = head->next;
        int sum = 0;
        while(p)
        {
            
            if(p->val == 0)
            {
                v.push_back(sum);
                sum = 0;
            }
            else
            {
                sum += p->val;
            }
            
            p = p->next;
        }
        
        p = head;
        ListNode* prev;
        int k = 0;
        while(k<v.size())
        {
            p->val = v[k++];
            prev = p;
            p = p->next;
        }
        
        while(p)
        {
            ListNode* t = p;
            prev->next = p->next;
            delete t;
            p = prev->next;
            
        }
        
        
        return head;
        
        
        
    }
};