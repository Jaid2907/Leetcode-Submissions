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
    int ans = 0;
    void preorder (TreeNode* root, TreeNode* prev, unordered_map<TreeNode*,int>& mp){
        
        if(root == NULL)
            return ;
        
            preorder(root->left, root,mp);
            preorder(root->right, root,mp);
        
            
        if((prev == NULL && mp.find(root) == mp.end()) || mp.find(root->left) == mp.end() || mp.find(root->right) == mp.end()){
            ans++;
            mp[root]++;
            mp[root->left]++;
            mp[root->right]++;
            mp[prev]++;
        }
            
        
        
       
    }
    int minCameraCover(TreeNode* root) {
        
        
        if(!root)
            return 0;
       unordered_map<TreeNode*,int> mp;
        mp[NULL]++;
        preorder(root,NULL,mp);
        return ans;
    }
};