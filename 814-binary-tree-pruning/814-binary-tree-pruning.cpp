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
    bool helper (TreeNode* root){
        if(!root)
            return false;
        
        bool ans = false;
        
        bool a = helper(root->left);
        bool b = helper(root->right);
        if(!a)
            root->left = NULL;
        if(!b)
            root->right = NULL;
        
        
        return a || b || root->val;
    }
    TreeNode* pruneTree(TreeNode* root) {
     
        helper(root);
            
        if(!root->left && !root->right)
            return root->val == 1 ? root : NULL;
        
        return root;
    }
};