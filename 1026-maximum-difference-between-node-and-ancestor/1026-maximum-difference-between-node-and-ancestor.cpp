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
    void helper(TreeNode* root, int maxi, int mini, int& ans){
        if(!root)
            return;
        
        helper(root->left, max(maxi,root->val), min(mini,root->val), ans);
        
        ans = max({ans,abs(root->val - maxi), abs(root->val - mini)});
        
        helper(root->right, max(maxi,root->val), min(mini, root->val),ans);
    }
    int maxAncestorDiff(TreeNode* root) {
        
        if(!root)
            return 0; 
        int ans = 0;
        helper(root,root->val, root->val, ans);
        return ans;
    }
};