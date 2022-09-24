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
    void helper (TreeNode* root, int target, int sum, vector<int>& temp, vector<vector<int>>& ans){
        if(!root)
            return;
        if(!root->left && !root->right){
            sum += root->val;
            temp.push_back(root->val);
            if(sum == target){
                ans.push_back(temp);
            }
            
            temp.pop_back();
            return;
        }
        
        temp.push_back(root->val);
        helper(root->left, target,sum+root->val,temp,ans);
        helper(root->right,target,sum+root->val,temp,ans);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(root,targetSum,0,temp,ans);
        return ans;
    }
};