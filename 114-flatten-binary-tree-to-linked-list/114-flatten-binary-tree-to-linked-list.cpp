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
    int f=-1;
    void solve(TreeNode*root,TreeNode*&prev, TreeNode* parentLeft, TreeNode* parentRight)
    {
        
        if(root==NULL)
            return;
        
        if(f==-1)
        {
            
            f=0;
        }
        else
        {
            if(parentLeft)
                parentLeft->left = NULL;
            else parentRight->right = NULL;
            
            prev->left = root;
            prev = prev->left;
        }
        
        solve(root->left,prev,root,NULL);
        solve(root->right,prev,NULL,root);
       
        
        
        
        
        return;
    }
    void preorder (TreeNode* root){
        if(!root)
            return;
        
        TreeNode* temp = root->left;
        root->right = temp;
        root->left = NULL;
        
        preorder(root->right);
    }
    void flatten(TreeNode* root) {
        TreeNode* prev=root;
        solve(root,prev,NULL,NULL);
        preorder(root);
        
        
    }
};