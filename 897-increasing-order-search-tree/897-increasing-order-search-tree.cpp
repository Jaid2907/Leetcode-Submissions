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
    TreeNode* head;
    void helper(TreeNode* root, TreeNode* &prev){
        if(!root)
            return;
        
        helper(root->left, prev);
        if(!prev){
            head = root;
        }else{
            prev->right = root;
        }
        prev = root;
        prev->left = NULL;

        helper(root->right,prev);
        
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* prev = NULL;
        helper(root,prev);
        return head;
    }
};