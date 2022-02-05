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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        vector<int> v;
        
        
        for(auto &it: lists)
        {
            while(it)
            {
                v.push_back(it->val);
                it = it->next;
            }
        }
        if(v.size()==0)
            return NULL;
        sort(v.begin(),v.end());
        ListNode* head =  new ListNode;
        head->val = v[0];
        head->next = NULL;
        ListNode* last;
        last = head;
        
        for(auto it= v.begin()+1; it!=v.end(); it++)
        {
            ListNode* p = new ListNode;
            last->next = p;
            p->val = *it;
            p->next = NULL;
            last = p;
            
        }
        
        
        return head;
    }
};