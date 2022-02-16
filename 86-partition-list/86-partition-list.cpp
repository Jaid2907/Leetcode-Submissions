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
    ListNode* partition(ListNode* head, int x) {
        //Space O(n) and Time O(n)
        vector<int> less,greater;
        
        ListNode* p = head;
        
        while(p)
        {
            if(p->val<x)
                less.push_back(p->val);
            else
                greater.push_back(p->val);
            p = p->next;
        }
        p = head;
        int i = 0;
        int n = less.size();
        while(i<n)
        {
            p->val = less[i++];
            p = p->next;
        }
        i = 0;
        while(p)
        {
            p->val = greater[i++];
            p = p->next;
        }
        return head;
    }
};