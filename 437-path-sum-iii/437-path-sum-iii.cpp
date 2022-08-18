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
    int cnt = 0;
    void preorder (TreeNode* root, int target,long long int sum,unordered_map<long long int,int>& mp){
        
       
        if(!root){
            return ;
        }

        sum += root->val;
        if(mp.find(sum - target) != mp.end()){
            cnt += mp[sum - target];
        }
        
        
        mp[sum]++;
        preorder(root->left,target,sum,mp);
        preorder(root->right,target,sum,mp);
        
        mp[sum]--;
        sum -= root->val;
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        
        unordered_map<long long int,int> mp;
        mp[0] = 1;
        
        preorder(root,targetSum,0,mp);
        return cnt;
    }
};