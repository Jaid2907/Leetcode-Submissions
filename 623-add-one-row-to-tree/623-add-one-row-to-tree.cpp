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
    void helper(TreeNode* root, int level,int depth, int val){
        if(!root)
            return ;
        
        if(level == depth){
            
            TreeNode* temp_left = root->left;
            TreeNode* temp_right = root->right;
            
            root->left = new TreeNode(val);
            root->left->left = temp_left;
            
            root->right = new TreeNode(val);
            root->right->right = temp_right;
            
            return;
        }
        helper(root->left, level + 1, depth, val);
        helper(root->right, level + 1, depth, val);
        
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* new_root = new TreeNode(val);
            new_root->left = root;
            return new_root;
        }
    
        
        helper(root,1, depth-1,val);
        
        return root;
        
    }
};