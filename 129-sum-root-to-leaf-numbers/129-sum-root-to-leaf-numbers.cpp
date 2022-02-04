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
    void preorder(TreeNode* root, vector<string>& ds, string& s)
    {
        if(root)
        {
            if(!root->left && !root->right)
            {
                s.push_back(48+root->val);
                ds.push_back(s);
                s.pop_back();
                return ;
            }
            
            s.push_back(48+root->val);
            preorder(root->left, ds,s);
            preorder(root->right,ds,s);
            s.pop_back();
        }
        
    }
    int sumNumbers(TreeNode* root) {
        vector<string> ds;
        string s ="";
        int sum = 0;
        preorder(root,ds,s);
        for(auto &it: ds)
        {
            sum += stoi(it);
        }
        return sum;
    }
};