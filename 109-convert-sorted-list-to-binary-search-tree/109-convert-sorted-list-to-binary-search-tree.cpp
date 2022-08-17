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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     ListNode* findMiddle (ListNode* start, ListNode* end){
         ListNode* slow = start;
         ListNode* fast = start;
         
         while(fast != end && fast->next != end){
             slow = slow->next;
             fast = fast->next->next;
         }
         
         return slow;
     }
     TreeNode* helper(ListNode* low, ListNode*  high){
         
         if(low == high)
             return NULL;
         if(low->next == high){
             return new TreeNode(low->val);
         }
             
         ListNode* mid = findMiddle(low,high);
         TreeNode* root = new TreeNode(mid->val);
         
         root->left = helper(low, mid);
         root->right = helper(mid->next,high);
         
         return root;
         
     }
    TreeNode* sortedListToBST(ListNode* head) {
        
    
        return helper(head,NULL);
    }
};