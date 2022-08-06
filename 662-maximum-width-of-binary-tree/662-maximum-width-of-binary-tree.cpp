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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        
        int ans = INT_MIN;
        
        queue<pair<TreeNode*,long long int>> q;
        q.push({root,0});
        
        
        while(!q.empty()){
            int size = q.size();
            long long int mini = q.front().second;
            int left = 0, right = 0;
            for(int i = 0; i<size; i++){
                
                auto node = q.front();
                q.pop();
                long long int curr_id = node.second - mini;
                
                
                if(i == 0){
                    left = curr_id;
                }
                if(i == size-1){
                 right = curr_id;   
                }
                if(node.first->left){
                    q.push({node.first->left, curr_id*2+1});
                }
                if(node.first->right){
                    q.push({node.first->right, curr_id*2+2});
                }
                
            }
            ans = max(ans, right-left+1);
            
        }
        
        return ans;
        
        
    }
};