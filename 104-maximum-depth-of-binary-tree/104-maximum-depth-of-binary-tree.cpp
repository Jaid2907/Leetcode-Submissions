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
private:

    
public:
    
    int maxDepth(TreeNode* root) {
        
        //By using level order traversal
        if(root==NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int height=0;
        
        while(!q.empty())
        {
            
            int size = q.size();
            
            while(size--)
            {
                TreeNode* p = q.front();
                q.pop();
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
                
                
            }
            height++;
        }
        
        return height;
        
        
    
        
    }
};