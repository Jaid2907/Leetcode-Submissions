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
    void helper (TreeNode* root, string& ans){
        if(!root->left && !root->right){
            // ans += '(';
            // ans += to_string(root->val);
            // ans += ')';
            
            return;
        }
        
        
        if(root->left){
            ans += '(';
            ans += to_string(root->left->val);
            helper(root->left, ans);
            ans += ')';
        }
        else
            ans += "()";
        
        if(root->right){
            ans += '(';
            ans += to_string(root->right->val);
            helper(root->right, ans);
            ans += ')';
        }
       
            
    }
    string tree2str(TreeNode* root) {
        string ans = to_string(root->val);
        helper(root, ans);
        
        return ans;
            
    }
};