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
    bool preorder(TreeNode* root, int val){
        
        if(!root)
            return true;
        if(root->val != val)
            return false;
        bool a = preorder(root->right,val);
        bool b = preorder(root->left, val);
        
        if(a && b)
            return true;
        return false;
        
    }
    bool isUnivalTree(TreeNode* root) {
        
        if(!root)
            return true;
        int val = root->val;
        
        return preorder(root,val);
        
        
        
    }
};