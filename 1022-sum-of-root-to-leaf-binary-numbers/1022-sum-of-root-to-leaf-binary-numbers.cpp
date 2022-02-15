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
    void preorder(TreeNode* root, vector<int>& v, int& sum)
    {
        
        if(root && !root->left && !root->right)
        {  
            v.push_back(root->val);
            int n = v.size();
            int power = pow(2,n-1);
            for(int i = 0; i<n; i++)
            {
                sum  = sum + v[i] * power;
                power/=2;
            }
           
            v.pop_back();
          
            return;
        }
        if(root)
        {
        v.push_back(root->val);
        preorder(root->left, v, sum);
        preorder(root->right,v, sum);
        v.pop_back();
        
        }
       
    }
    int sumRootToLeaf(TreeNode* root) {
        
        vector<int> v;
        int sum = 0;
        preorder(root,v,sum);
        
        return sum;
        
    }
};