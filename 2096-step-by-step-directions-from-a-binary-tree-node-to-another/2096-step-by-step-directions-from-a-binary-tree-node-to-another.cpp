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
    string path;
    void findParent (TreeNode* root, unordered_map<TreeNode*,TreeNode*>& mp){
        if(!root)
            return ;
        
        if(root->left)
            mp[root->left] = root;
        if(root->right)
            mp[root->right] = root;
        
        findParent(root->left, mp);
        findParent(root->right,mp);
    }
    void findPointer(TreeNode* root, TreeNode*& target, int target_val){
        if(!root)
            return;
        
        if(root->val == target_val){
            target = root;
            return;
        }
        
        findPointer(root->left,target,target_val);
        findPointer(root->right,target,target_val);
        
    }
    
    void dfs(TreeNode* root, string& ans, TreeNode* end,unordered_map<TreeNode*,int>& vis,unordered_map<TreeNode*,TreeNode*>& mp){
        if(!root || vis[root])
            return;
        vis[root]++;
        
        
        if(root == end){
            path = ans;
            return;
        }
        ans += 'U';
        dfs(mp[root],ans,end,vis,mp);
        ans.pop_back();
        
        ans += 'L';
        dfs(root->left,ans,end,vis,mp);
        ans.pop_back();
        
        
        ans += 'R';
        dfs(root->right,ans,end,vis,mp);
        ans.pop_back();
        
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<TreeNode* , TreeNode*> mp;
        unordered_map<TreeNode*,int> vis;
        mp[root] = NULL;
        string ans = "";
        
        TreeNode* start,*end;
        findPointer(root,start,startValue);
        findPointer(root,end,destValue);
        
        findParent(root,mp);
        dfs(start,ans,end,vis,mp);
        
        
        return path;
        
    }
};