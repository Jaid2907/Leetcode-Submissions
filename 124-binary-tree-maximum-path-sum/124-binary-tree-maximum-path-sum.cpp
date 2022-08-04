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
    int helper(TreeNode* root, int& ans){
        
        if(!root)
            return 0;
        
        int lh =  helper(root->left, ans);
        int rh =  helper(root->right, ans);
        
        ans =   max({ans, lh + rh + root->val, root->val, lh + root->val, rh + root->val});
        
        return root->val + max({lh,rh,0});
        
    }
        
    int maxPathSum(TreeNode* root) {
        int ans =INT_MIN;
        
        helper(root,ans);
        
        return ans;
    }
};