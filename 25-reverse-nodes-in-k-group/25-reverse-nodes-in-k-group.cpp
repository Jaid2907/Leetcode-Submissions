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
    vector<ListNode*> reverse(ListNode* start, ListNode* end, int k)
    {
        ListNode* p = start;
        ListNode* q = NULL, *r = NULL;
        
        int cnt = 0;
        while(p && cnt<k)
        {
            q = p;
            p=p->next;
            q->next = r;
            r = q;
            cnt++;
            
        }
        
        vector<ListNode*> v;
        v.push_back(r);
        v.push_back(start);
        return v;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* p = head;
        int cnt = 1;
        ListNode* new_head, *prev = NULL;
        int flag = 0;
        
        while(p)
        {
            ListNode* start = p;
            cnt = 1;
            while(p && cnt < k )
            {
                p=p->next;
                cnt++;
            }
             if(cnt<k || p==NULL)
                break;
            ListNode* end = p;
            ListNode* temp = NULL;
            if(p)
             temp = p->next;
           
            
            vector<ListNode*> v;
            v = reverse(start,end, k);
            if(flag ==0 )
            {
                new_head = v[0];
                prev = v[1];
                prev->next = temp;
                flag = 1;
                p = temp;
                continue;
            }
            
            prev->next = v[0];
            v[1]->next = temp;
            prev = v[1];
            p=temp;
            
            
        }
        return new_head;   
        
    }
};