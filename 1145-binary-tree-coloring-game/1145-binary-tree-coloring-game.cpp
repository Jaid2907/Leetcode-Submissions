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
    int findCountofNodes (TreeNode* root){
        
        if(!root)
            return 0;
        
        return 1 + findCountofNodes(root->left) + findCountofNodes(root->right);
    }
    
    void findPos (TreeNode* root, int x, TreeNode* &pos){
        if(!root)
            return;
        
        if(root->val == x){
            pos = root;
            return;
        }
        
        findPos(root->left,x,pos);
        findPos(root->right,x,pos);
            
    } 
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* pos = NULL;
        findPos(root,x,pos); 
        
        int leftNodes = findCountofNodes(pos->left);
        int rightNodes = findCountofNodes(pos->right);
        
        int parentNodes = n - (leftNodes + rightNodes + 1);
        
        if(leftNodes > (rightNodes + parentNodes + 1) || rightNodes > (leftNodes + parentNodes + 1) || parentNodes > (leftNodes + rightNodes + 1))
            return true;
        return false;
    }
};