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
    void preorder (TreeNode* root, int target,long long int sum, bool picked){
        
       
        if(!root){
            return ;
        }

        sum += root->val;
        if(sum == target){
            cnt++;   
        }
                
        preorder(root->left,target,sum,true);
        preorder(root->right,target,sum,true);
        sum -= root->val;
        
        
        if(!picked){
        preorder(root->left,target,sum,picked);
        preorder(root->right,target,sum,picked);    
        }
        
        
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        
        
        preorder(root,targetSum,0,false);
        return cnt;
    }
};