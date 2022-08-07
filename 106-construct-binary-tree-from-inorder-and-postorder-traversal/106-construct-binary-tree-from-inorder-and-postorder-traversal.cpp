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
    TreeNode* buildTree (vector<int>& postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int,int>& mp){
    if(postStart > postEnd || inStart > inEnd)
        return NULL;
    TreeNode* root = new TreeNode(postorder[postEnd]);
    int inRoot = mp[root->val];
    int numsStart = inRoot - inStart;
  
    root->left = buildTree(postorder, postStart, postStart+numsStart-1,inorder, inStart, inRoot-1,mp);
    root->right = buildTree(postorder, postStart+numsStart, postEnd-1,inorder, inRoot+1,inEnd,mp);
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        int n = inorder.size();
        
        for(int i = 0; i<n; i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = buildTree(postorder,0,n-1,inorder,0,n-1,mp);
        return root;
    }
};