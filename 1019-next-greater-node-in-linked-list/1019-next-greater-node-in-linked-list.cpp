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
    ListNode* reverseLL(ListNode* head){
        ListNode* p = head;
        ListNode* q = NULL;
        ListNode* r = NULL;
        
        while(p){
            q = p;
            p = p->next;
            q->next = r;
            r = q;
        }
        
        return r;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        if(!head)
            return ans;    
        ListNode* rev = reverseLL(head);
        
        ListNode* curr = rev->next;
        stack<int> st;
        ans.push_back(0);
        st.push(rev->val);
        
        while(curr){
            
            while(!st.empty() && st.top() <= curr->val)
                st.pop();
            
            if(!st.empty())
                ans.push_back(st.top());
            else
                ans.push_back(0);
            st.push(curr->val);
            curr = curr->next;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};